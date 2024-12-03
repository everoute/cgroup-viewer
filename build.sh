#!/usr/bin/env bash
set -E -e -u -o pipefail

cd "$(dirname "$0")"
symbol=(
	mem_cgroup_iter
	first_online_pgdat
	next_online_pgdat
)

for i in "${symbol[@]}"; do
	a=$(sudo cat /proc/kallsyms | grep " $i$" | awk '{print $1}')
	echo "$i -- $a"
	set -x
	sed -i "s/$i)0xffff.*;/$i)0x$a;/" cg.c
	set +x
done

