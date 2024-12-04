#include <linux/kernel.h>
#include <linux/memcontrol.h>
#include <linux/module.h>

typedef struct mem_cgroup *(*type_mem_cgroup_iter)(
    struct mem_cgroup *root, struct mem_cgroup *prev,
    struct mem_cgroup_reclaim_cookie *reclaim);
typedef struct pglist_data *(*type_first_online_pgdat)(void);
typedef struct pglist_data *(*typde_next_online_pgdat)(
    struct pglist_data *pgdat);

type_mem_cgroup_iter iter = (type_mem_cgroup_iter)0xffffffff81407640;
type_first_online_pgdat first = (type_first_online_pgdat)0xffffffff8134c800;
typde_next_online_pgdat next = (typde_next_online_pgdat)0xffffffff8134c850;

static void snapshot_refaults(struct mem_cgroup *root_memcg, pg_data_t *pgdat) {
  struct mem_cgroup *memcg;

  memcg = iter(root_memcg, NULL, NULL);
  do {
    	pr_info("[smartx:%s:%d] %s %px\n", __FUNCTION__, __LINE__,
        memcg->css.cgroup->kn->name, memcg);
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
