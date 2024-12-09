#include <linux/kernel.h>
#include <linux/memcontrol.h>
#include <linux/module.h>
#include <linux/page_counter.h>
#include <linux/mm.h>
#include <linux/mm_inline.h>

typedef struct mem_cgroup *(*type_mem_cgroup_iter)(
    struct mem_cgroup *root, struct mem_cgroup *prev,
    struct mem_cgroup_reclaim_cookie *reclaim);
typedef struct pglist_data *(*type_first_online_pgdat)(void);
typedef struct pglist_data *(*type_next_online_pgdat)(
    struct pglist_data *pgdat);

type_mem_cgroup_iter iter = (type_mem_cgroup_iter)0xffffffff81407640;
type_first_online_pgdat first = (type_first_online_pgdat)0xffffffff8134c800;
type_next_online_pgdat next = (type_next_online_pgdat)0xffffffff8134c850;

static inline
unsigned long mem_cgroup_get_lru_size(struct lruvec *lruvec, enum lru_list lru)
{
	unsigned long nr_pages = 0;
	int zid;

	for (zid = 0; zid < MAX_NR_ZONES; zid++)
		nr_pages += mem_cgroup_get_zone_lru_size(lruvec, lru, zid);
	return nr_pages;
}

static void list_pages(struct lruvec *lruvec) {
    enum lru_list lru;

    for_each_lru(lru) {
        if (mem_cgroup_get_lru_size(lruvec, lru) > 0) {
            printk(KERN_CONT " LRU%d=%lu", lru, mem_cgroup_get_lru_size(lruvec, lru));
            if (lru == 0) {
                struct list_head *src = &lruvec->lists[lru];
                struct page *page = lru_to_page(src);
                struct address_space *mapping = page_mapping(page);
                printk(KERN_CONT " inode=%lu offset=%lu", mapping->host->i_ino, page->index);
            }
        }
    }
}

static void snapshot_refaults(struct mem_cgroup *root_memcg, pg_data_t *pgdat) {
  struct mem_cgroup *memcg;

  memcg = iter(root_memcg, NULL, NULL);
  do {
//        int idx = NR_LRU_BASE;
        struct lruvec *lruvec = mem_cgroup_lruvec(pgdat, memcg);

        pr_info("[smartx:%s:%d] %s %px mem=%lu swap=%lu memsw=%lu kmem=%lu tcpmem=%lu id=%d",
            __FUNCTION__,
            __LINE__,
            memcg->css.cgroup->kn->name,
            memcg,
            page_counter_read(&memcg->memory),
            page_counter_read(&memcg->swap),
            page_counter_read(&memcg->memsw),
            page_counter_read(&memcg->kmem),
            page_counter_read(&memcg->tcpmem),
            memcg->id.id);
//        while (idx < MEMCG_NR_STAT) {
//            printk(KERN_CONT " %d=%lu", idx, memcg_page_state(memcg, idx));
//            idx++;
//        }
        list_pages(lruvec);
        cond_resched();
  } while ((memcg = iter(root_memcg, memcg, NULL)));
}

#define my_for_each_online_pgdat(pgdat)                                        \
  for (pgdat = first(); pgdat; pgdat = next(pgdat))

static void test_it(void) {
  struct pglist_data *pgdat;
  my_for_each_online_pgdat(pgdat) {
    pr_info("[smartx:%s:%d] %d\n", __FUNCTION__, __LINE__, pgdat->node_id);
    snapshot_refaults(NULL, pgdat);
    break;
  }
}

static int __init cg_viewer_init(void) {
  test_it();
  return 0;
}

static void __exit cg_viewer_exit(void) {}

module_init(cg_viewer_init);
module_exit(cg_viewer_exit);
MODULE_LICENSE("GPL");
