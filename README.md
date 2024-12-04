使用方法:

## 本地
1. 在测试机器上执行，获取符号地址
```sh
symbol=(
	mem_cgroup_iter
	first_online_pgdat
	next_online_pgdat
)

for i in "${symbol[@]}"; do
	a=$(sudo cat /proc/kallsyms | grep " $i$" | awk '{print $1}')
	echo "$i -- $a"
done
```
2. 在把 cg.c 中的地址替换掉
3. make 构建 cg.ko
4. 上传 cg.ko 到客户环境中并且 sudo insmod cg.ko

## 客户环境构建

1. 客户环境安装 kernel-devel
2. ./build.sh
3. dmesg

## 参考案例
```txt
[47698.618593] [smartx:test_it:32] 0
[47698.618795] [smartx:snapshot_refaults:22]
[47698.619016] [smartx:snapshot_refaults:22] system.slice
[47698.619294] [smartx:snapshot_refaults:22] systemd-journald.service
[47698.619679] [smartx:snapshot_refaults:22] -.mount
[47698.619941] [smartx:snapshot_refaults:22] systemd-journald.socket
[47698.620276] [smartx:snapshot_refaults:22] systemd-journald-dev-log.socket
[47698.620654] [smartx:snapshot_refaults:22] systemd-udevd.service
[47698.620978] [smartx:snapshot_refaults:22] sys-kernel-config.mount
[47698.621310] [smartx:snapshot_refaults:22] sysroot.mount
[47698.621606] [smartx:snapshot_refaults:22] systemd-fsck-root.service
[47698.621947] [smartx:snapshot_refaults:22] dracut-pre-pivot.service
[47698.622283] [smartx:snapshot_refaults:22] system-getty.slice
[47698.622605] [smartx:snapshot_refaults:22] getty@tty1.service
[47698.622912] [smartx:snapshot_refaults:22] system-serial\x2dgetty.slice
[47698.623264] [smartx:snapshot_refaults:22] serial-getty@hvc0.service
[47698.623614] [smartx:snapshot_refaults:22] serial-getty@ttyS0.service
[47698.623956] [smartx:snapshot_refaults:22] system-sshd\x2dkeygen.slice
[47698.624293] [smartx:snapshot_refaults:22] system-systemd\x2dfsck.slice
[47698.624641] [smartx:snapshot_refaults:22] systemd-fsck@dev-disk-by\x2duuid-79cf12c3\x2d79da\x2d40ac\x2d98ed\x2d1aaf83790f50.service
[47698.625234] [smartx:snapshot_refaults:22] systemd-fsck@dev-disk-by\x2duuid-79cf12c3\x2d79da\x2d40ac\x2d98ed\x2d1aaf83790f50.service
[47698.625842] [smartx:snapshot_refaults:22] system-zbs.slice
[47698.626123] [smartx:snapshot_refaults:22] system-zbs-others.slice
[47698.626442] [smartx:snapshot_refaults:22] ntpd.service
[47698.626705] [smartx:snapshot_refaults:22] zbs-deploy-server.service
[47698.627031] [smartx:snapshot_refaults:22] nginx.service
[47698.627299] [smartx:snapshot_refaults:22] dev-hugepages.mount
[47698.627602] [smartx:snapshot_refaults:22] dev-mqueue.mount
[47698.627883] [smartx:snapshot_refaults:22] sys-kernel-debug.mount
[47698.628191] [smartx:snapshot_refaults:22] cgconfig.service
[47698.628479] [smartx:snapshot_refaults:22] kmod-static-nodes.service
[47698.628803] [smartx:snapshot_refaults:22] lvm2-monitor.service
[47698.629103] [smartx:snapshot_refaults:22] systemd-journald.service
[47698.629423] [smartx:snapshot_refaults:22] systemd-modules-load.service
[47698.629759] [smartx:snapshot_refaults:22] systemd-remount-fs.service
[47698.630083] [smartx:snapshot_refaults:22] systemd-udev-trigger.service
[47698.630423] [smartx:snapshot_refaults:22] systemd-journald-audit.socket
[47698.630762] [smartx:snapshot_refaults:22] dm-event.socket
[47698.631035] [smartx:snapshot_refaults:22] rpcbind.socket
[47698.631307] [smartx:snapshot_refaults:22] lvm2-lvmpolld.socket
[47698.631613] [smartx:snapshot_refaults:22] systemd-udevd-kernel.socket
[47698.631942] [smartx:snapshot_refaults:22] systemd-initctl.socket
[47698.632251] [smartx:snapshot_refaults:22] systemd-coredump.socket
[47698.632574] [smartx:snapshot_refaults:22] systemd-udevd-control.socket
[47698.632905] [smartx:snapshot_refaults:22] cgconfig.service
[47698.633186] [smartx:snapshot_refaults:22] systemd-remount-fs.service
[47698.633530] [smartx:snapshot_refaults:22] systemd-modules-load.service
[47698.633983] [smartx:snapshot_refaults:22] kmod-static-nodes.service
[47698.634452] [smartx:snapshot_refaults:22] sys-fs-fuse-connections.mount
[47698.634903] [smartx:snapshot_refaults:22] systemd-journal-flush.service
[47698.635368] [smartx:snapshot_refaults:22] systemd-random-seed.service
[47698.635805] [smartx:snapshot_refaults:22] systemd-sysctl.service
[47698.636216] [smartx:snapshot_refaults:22] systemd-tmpfiles-setup-dev.service
[47698.636698] [smartx:snapshot_refaults:22] systemd-udevd.service
[47698.637115] [smartx:snapshot_refaults:22] systemd-tmpfiles-setup-dev.service
[47698.637615] [smartx:snapshot_refaults:22] systemd-journal-flush.service
[47698.638093] [smartx:snapshot_refaults:22] systemd-sysctl.service
[47698.638531] [smartx:snapshot_refaults:22] systemd-udev-trigger.service
[47698.639020] [smartx:snapshot_refaults:22] systemd-random-seed.service
[47698.639520] [smartx:snapshot_refaults:22] lvm2-monitor.service
[47698.639951] [smartx:snapshot_refaults:22] boot.mount
[47698.640339] [smartx:snapshot_refaults:22] dracut-shutdown.service
[47698.640775] [smartx:snapshot_refaults:22] openibd.service
[47698.641173] [smartx:snapshot_refaults:22] systemd-tmpfiles-setup.service
[47698.641647] [smartx:snapshot_refaults:22] var-lib-nfs-rpc_pipefs.mount
[47698.642108] [smartx:snapshot_refaults:22] auditd.service
[47698.642510] [smartx:snapshot_refaults:22] mdmonitor.service
[47698.642923] [smartx:snapshot_refaults:22] systemd-tmpfiles-setup.service
[47698.643399] [smartx:snapshot_refaults:22] dracut-shutdown.service
[47698.643834] [smartx:snapshot_refaults:22] systemd-update-utmp.service
[47698.644289] [smartx:snapshot_refaults:22] cgred.service
[47698.644676] [smartx:snapshot_refaults:22] dbus.service
[47698.645057] [smartx:snapshot_refaults:22] irqbalance.service
[47698.645524] [smartx:snapshot_refaults:22] lm_sensors.service
[47698.645935] [smartx:snapshot_refaults:22] lttng-sessiond.service
[47698.646369] [smartx:snapshot_refaults:22] netcf-transaction.service
[47698.646806] [smartx:snapshot_refaults:22] ovsdb-server.service
[47698.647214] [smartx:snapshot_refaults:22] polkit.service
[47698.647688] [smartx:snapshot_refaults:22] rngd.service
[47698.648359] [smartx:snapshot_refaults:22] smartd.service
[47698.648914] [smartx:snapshot_refaults:22] smtx-init-cgconfig.service
[47698.649376] [smartx:snapshot_refaults:22] sysstat.service
[47698.649794] [smartx:snapshot_refaults:22] systemd-logind.service
[47698.650223] [smartx:snapshot_refaults:22] systemtap.service
[47698.650650] [smartx:snapshot_refaults:22] virtlockd-admin.socket
[47698.651097] [smartx:snapshot_refaults:22] virtlogd-admin.socket
[47698.651543] [smartx:snapshot_refaults:22] iscsid.socket
[47698.652225] [smartx:snapshot_refaults:22] systemd-update-utmp.service
[47698.652844] [smartx:snapshot_refaults:22] dbus.socket
[47698.653218] [smartx:snapshot_refaults:22] sys-kernel-debug-tracing.mount
[47698.653667] [smartx:snapshot_refaults:22] hwclock-save.service
[47698.654067] [smartx:snapshot_refaults:22] netcf-transaction.service
[47698.654562] [smartx:snapshot_refaults:22] sysstat.service
[47698.654942] [smartx:snapshot_refaults:22] systemtap.service
[47698.655338] [smartx:snapshot_refaults:22] ovs-vswitchd.service
[47698.655743] [smartx:snapshot_refaults:22] ovs-delete-transient-ports.service
[47698.656207] [smartx:snapshot_refaults:22] network.service
[47698.656598] [smartx:snapshot_refaults:22] openvswitch.service
[47698.656996] [smartx:snapshot_refaults:22] smtx-config-hugepage.service
[47698.657460] [smartx:snapshot_refaults:22] smtx-init-cgconfig.service
[47698.657891] [smartx:snapshot_refaults:22] cgconfig.service
[47698.658277] [smartx:snapshot_refaults:22] hugepage-manager.service
[47698.658719] [smartx:snapshot_refaults:22] cloudtower-installer.service
[47698.659168] [smartx:snapshot_refaults:22] fisheye-pre-boot.service
[47698.659604] [smartx:snapshot_refaults:22] gssproxy.service
[47698.659995] [smartx:snapshot_refaults:22] iscsid.service
[47698.660407] [smartx:snapshot_refaults:22] rpc-statd-notify.service
[47698.660838] [smartx:snapshot_refaults:22] rsyslog.service
[47698.661225] [smartx:snapshot_refaults:22] sshd.service
[47698.661598] [smartx:snapshot_refaults:22] tuned.service
[47698.661975] [smartx:snapshot_refaults:22] hugepage-manager.service
[47698.662415] [smartx:snapshot_refaults:22] rpc-statd-notify.service
[47698.662845] [smartx:snapshot_refaults:22] iscsi.service
[47698.663222] [smartx:snapshot_refaults:22] kdump.service
[47698.663603] [smartx:snapshot_refaults:22] systemd-user-sessions.service
[47698.664047] [smartx:snapshot_refaults:22] iscsi.service
[47698.664475] [smartx:snapshot_refaults:22] crond.service
[47698.664852] [smartx:snapshot_refaults:22] systemd-user-sessions.service
[47698.665298] [smartx:snapshot_refaults:22] systemd-hostnamed.service
[47698.665746] [smartx:snapshot_refaults:22] run-user-0.mount
[47698.666126] [smartx:snapshot_refaults:22] kdump.service
[47698.666498] [smartx:snapshot_refaults:22] network.service
[47698.666873] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.667281] [smartx:snapshot_refaults:22] cgred.service
[47698.667643] [smartx:snapshot_refaults:22] dnf-makecache.service
[47698.668042] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.668500] [smartx:snapshot_refaults:22] systemd-tmpfiles-clean.service
[47698.668935] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.669353] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.669831] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.670316] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.670792] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.671262] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.671747] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.672218] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.672691] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.673227] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.673823] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.674533] [smartx:snapshot_refaults:22] dnf-makecache.service
[47698.675218] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.675853] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.676274] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.676684] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.677097] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.677510] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.677917] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.678317] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.678718] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.679118] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.679520] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.679918] [smartx:snapshot_refaults:22] sysstat-summary.service
[47698.680311] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.680707] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.681100] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.681493] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.681881] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.682265] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.682651] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.683028] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.683423] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.683819] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.684195] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.684603] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.685013] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.685429] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.685795] [smartx:snapshot_refaults:22] dnf-makecache.service
[47698.686144] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.686507] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.686909] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.687290] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.687673] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.688039] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.688417] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.688956] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.689588] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.689956] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.690318] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.690680] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.691038] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.691409] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.691771] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.692130] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.692496] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.692868] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.693219] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.693576] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.693919] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.694261] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.694615] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.694953] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.695292] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.695723] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.696342] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.696802] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.697170] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.697538] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.697900] [smartx:snapshot_refaults:22] dnf-makecache.service
[47698.698251] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.698622] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.698983] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.699354] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.699713] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.700076] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.700443] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.700807] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.701167] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.701534] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.701899] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.702260] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.702632] [smartx:snapshot_refaults:22] dnf-makecache.service
[47698.702987] [smartx:snapshot_refaults:22] init.scope
[47698.703292] [smartx:snapshot_refaults:22] user.slice
[47698.703600] [smartx:snapshot_refaults:22] user-0.slice
[47698.703916] [smartx:snapshot_refaults:22] user-runtime-dir@0.service
[47698.704298] [smartx:snapshot_refaults:22] user@0.service
[47698.704631] [smartx:snapshot_refaults:22] dbus.socket
[47698.704932] [smartx:snapshot_refaults:22] run-user-0.mount
[47698.705255] [smartx:snapshot_refaults:22] dev-mqueue.mount
[47698.705586] [smartx:snapshot_refaults:22] -.mount
[47698.705868] [smartx:snapshot_refaults:22] boot.mount
[47698.706165] [smartx:snapshot_refaults:22] sys-kernel-debug-tracing.mount
[47698.706559] [smartx:snapshot_refaults:22] sys-kernel-config.mount
[47698.706915] [smartx:snapshot_refaults:22] sys-fs-fuse-connections.mount
[47698.707299] [smartx:snapshot_refaults:22] var-lib-nfs-rpc_pipefs.mount
[47698.707681] [smartx:snapshot_refaults:22] dev-hugepages.mount
[47698.708026] [smartx:snapshot_refaults:22] init.scope
[47698.708348] [smartx:snapshot_refaults:22] sys-kernel-debug.mount
[47698.708711] [smartx:snapshot_refaults:22] user-runtime-dir@0.service
[47698.709095] [smartx:snapshot_refaults:22] session-1.scope
[47698.709434] [smartx:snapshot_refaults:22] session-3.scope
[47698.709772] [smartx:snapshot_refaults:22] session-4.scope
[47698.710106] [smartx:snapshot_refaults:22] session-5.scope
[47698.710444] [smartx:snapshot_refaults:22] session-31.scope
[47698.710809] [smartx:snapshot_refaults:22] session-49.scope
[47698.711155] [smartx:snapshot_refaults:22] session-53.scope
[47698.711499] [smartx:snapshot_refaults:22] session-64.scope
[47698.711981] [smartx:snapshot_refaults:22] session-68.scope
[47698.712435] [smartx:snapshot_refaults:22] session-69.scope
[47698.712857] [smartx:snapshot_refaults:22] session-80.scope
[47698.713262] [smartx:snapshot_refaults:22] session-85.scope
[47698.713650] [smartx:snapshot_refaults:22] session-109.scope
[47698.714009] [smartx:snapshot_refaults:22] session-114.scope
[47698.714379] [smartx:snapshot_refaults:22] session-123.scope
[47698.714742] [smartx:snapshot_refaults:22] session-127.scope
[47698.715101] [smartx:snapshot_refaults:22] session-129.scope
[47698.715464] [smartx:snapshot_refaults:22] session-130.scope
[47698.715827] [smartx:snapshot_refaults:22] session-131.scope
[47698.716181] [smartx:snapshot_refaults:22] session-133.scope
[47698.716535] [smartx:snapshot_refaults:22] session-134.scope
[47698.716886] [smartx:snapshot_refaults:22] session-135.scope
[47698.717233] [smartx:snapshot_refaults:22] session-138.scope
[47698.717589] [smartx:snapshot_refaults:22] session-139.scope
[47698.717934] [smartx:snapshot_refaults:22] session-141.scope
[47698.718279] [smartx:snapshot_refaults:22] test
[47698.718572] [smartx:snapshot_refaults:22] 0
[47698.718851] [smartx:snapshot_refaults:22] 1
[47698.719131] [smartx:snapshot_refaults:22] 2
[47698.719417] [smartx:snapshot_refaults:22] 3
[47698.719697] [smartx:snapshot_refaults:22] 4
[47698.719976] [smartx:snapshot_refaults:22] 5
[47698.720254] [smartx:snapshot_refaults:22] 6
[47698.720537] [smartx:snapshot_refaults:22] 7
[47698.720839] [smartx:snapshot_refaults:22] 8
[47698.721125] [smartx:snapshot_refaults:22] 9
[47698.721414] [smartx:snapshot_refaults:22] 10
[47698.721701] [smartx:snapshot_refaults:22] 11
[47698.721984] [smartx:snapshot_refaults:22] 12
[47698.722268] [smartx:snapshot_refaults:22] 13
[47698.722559] [smartx:snapshot_refaults:22] 14
[47698.722840] [smartx:snapshot_refaults:22] 15
[47698.723120] [smartx:snapshot_refaults:22] 16
[47698.723404] [smartx:snapshot_refaults:22] 17
[47698.723679] [smartx:snapshot_refaults:22] 18
[47698.723950] [smartx:snapshot_refaults:22] 19
[47698.724222] [smartx:snapshot_refaults:22] 20
[47698.724498] [smartx:snapshot_refaults:22] 21
[47698.724769] [smartx:snapshot_refaults:22] 22
[47698.725033] [smartx:snapshot_refaults:22] 23
[47698.725298] [smartx:snapshot_refaults:22] 24
[47698.725563] [smartx:test_it:32] 1
[47698.725779] [smartx:snapshot_refaults:22]
[47698.726035] [smartx:snapshot_refaults:22] system.slice
[47698.726359] [smartx:snapshot_refaults:22] systemd-journald.service
[47698.726731] [smartx:snapshot_refaults:22] -.mount
[47698.727021] [smartx:snapshot_refaults:22] systemd-journald.socket
[47698.727398] [smartx:snapshot_refaults:22] systemd-journald-dev-log.socket
[47698.727805] [smartx:snapshot_refaults:22] systemd-udevd.service
[47698.728167] [smartx:snapshot_refaults:22] sys-kernel-config.mount
[47698.728546] [smartx:snapshot_refaults:22] sysroot.mount
[47698.728874] [smartx:snapshot_refaults:22] systemd-fsck-root.service
[47698.729258] [smartx:snapshot_refaults:22] dracut-pre-pivot.service
[47698.729648] [smartx:snapshot_refaults:22] system-getty.slice
[47698.730001] [smartx:snapshot_refaults:22] getty@tty1.service
[47698.730365] [smartx:snapshot_refaults:22] system-serial\x2dgetty.slice
[47698.730774] [smartx:snapshot_refaults:22] serial-getty@hvc0.service
[47698.731164] [smartx:snapshot_refaults:22] serial-getty@ttyS0.service
[47698.731564] [smartx:snapshot_refaults:22] system-sshd\x2dkeygen.slice
[47698.731946] [smartx:snapshot_refaults:22] system-systemd\x2dfsck.slice
[47698.732347] [smartx:snapshot_refaults:22] systemd-fsck@dev-disk-by\x2duuid-79cf12c3\x2d79da\x2d40ac\x2d98ed\x2d1aaf83790f50.service
[47698.733019] [smartx:snapshot_refaults:22] systemd-fsck@dev-disk-by\x2duuid-79cf12c3\x2d79da\x2d40ac\x2d98ed\x2d1aaf83790f50.service
[47698.733707] [smartx:snapshot_refaults:22] system-zbs.slice
[47698.734065] [smartx:snapshot_refaults:22] system-zbs-others.slice
[47698.734488] [smartx:snapshot_refaults:22] ntpd.service
[47698.734833] [smartx:snapshot_refaults:22] zbs-deploy-server.service
[47698.735225] [smartx:snapshot_refaults:22] nginx.service
[47698.735584] [smartx:snapshot_refaults:22] dev-hugepages.mount
[47698.735948] [smartx:snapshot_refaults:22] dev-mqueue.mount
[47698.736315] [smartx:snapshot_refaults:22] sys-kernel-debug.mount
[47698.736816] [smartx:snapshot_refaults:22] cgconfig.service
[47698.737202] [smartx:snapshot_refaults:22] kmod-static-nodes.service
[47698.737638] [smartx:snapshot_refaults:22] lvm2-monitor.service
[47698.738032] [smartx:snapshot_refaults:22] systemd-journald.service
[47698.738482] [smartx:snapshot_refaults:22] systemd-modules-load.service
[47698.738916] [smartx:snapshot_refaults:22] systemd-remount-fs.service
[47698.739348] [smartx:snapshot_refaults:22] systemd-udev-trigger.service
[47698.739789] [smartx:snapshot_refaults:22] systemd-journald-audit.socket
[47698.740222] [smartx:snapshot_refaults:22] dm-event.socket
[47698.740604] [smartx:snapshot_refaults:22] rpcbind.socket
[47698.740969] [smartx:snapshot_refaults:22] lvm2-lvmpolld.socket
[47698.741375] [smartx:snapshot_refaults:22] systemd-udevd-kernel.socket
[47698.741819] [smartx:snapshot_refaults:22] systemd-initctl.socket
[47698.742226] [smartx:snapshot_refaults:22] systemd-coredump.socket
[47698.742648] [smartx:snapshot_refaults:22] systemd-udevd-control.socket
[47698.743088] [smartx:snapshot_refaults:22] cgconfig.service
[47698.743486] [smartx:snapshot_refaults:22] systemd-remount-fs.service
[47698.743918] [smartx:snapshot_refaults:22] systemd-modules-load.service
[47698.744368] [smartx:snapshot_refaults:22] kmod-static-nodes.service
[47698.744809] [smartx:snapshot_refaults:22] sys-fs-fuse-connections.mount
[47698.745258] [smartx:snapshot_refaults:22] systemd-journal-flush.service
[47698.745712] [smartx:snapshot_refaults:22] systemd-random-seed.service
[47698.746155] [smartx:snapshot_refaults:22] systemd-sysctl.service
[47698.746588] [smartx:snapshot_refaults:22] systemd-tmpfiles-setup-dev.service
[47698.747049] [smartx:snapshot_refaults:22] systemd-udevd.service
[47698.747519] [smartx:snapshot_refaults:22] systemd-tmpfiles-setup-dev.service
[47698.748003] [smartx:snapshot_refaults:22] systemd-journal-flush.service
[47698.748483] [smartx:snapshot_refaults:22] systemd-sysctl.service
[47698.748898] [smartx:snapshot_refaults:22] systemd-udev-trigger.service
[47698.749349] [smartx:snapshot_refaults:22] systemd-random-seed.service
[47698.749801] [smartx:snapshot_refaults:22] lvm2-monitor.service
[47698.750209] [smartx:snapshot_refaults:22] boot.mount
[47698.750581] [smartx:snapshot_refaults:22] dracut-shutdown.service
[47698.751005] [smartx:snapshot_refaults:22] openibd.service
[47698.751425] [smartx:snapshot_refaults:22] systemd-tmpfiles-setup.service
[47698.751881] [smartx:snapshot_refaults:22] var-lib-nfs-rpc_pipefs.mount
[47698.752325] [smartx:snapshot_refaults:22] auditd.service
[47698.752709] [smartx:snapshot_refaults:22] mdmonitor.service
[47698.753109] [smartx:snapshot_refaults:22] systemd-tmpfiles-setup.service
[47698.753572] [smartx:snapshot_refaults:22] dracut-shutdown.service
[47698.753989] [smartx:snapshot_refaults:22] systemd-update-utmp.service
[47698.754452] [smartx:snapshot_refaults:22] cgred.service
[47698.754829] [smartx:snapshot_refaults:22] dbus.service
[47698.755207] [smartx:snapshot_refaults:22] irqbalance.service
[47698.755612] [smartx:snapshot_refaults:22] lm_sensors.service
[47698.756005] [smartx:snapshot_refaults:22] lttng-sessiond.service
[47698.756448] [smartx:snapshot_refaults:22] netcf-transaction.service
[47698.756876] [smartx:snapshot_refaults:22] ovsdb-server.service
[47698.757279] [smartx:snapshot_refaults:22] polkit.service
[47698.757657] [smartx:snapshot_refaults:22] rngd.service
[47698.758025] [smartx:snapshot_refaults:22] smartd.service
[47698.758442] [smartx:snapshot_refaults:22] smtx-init-cgconfig.service
[47698.758873] [smartx:snapshot_refaults:22] sysstat.service
[47698.759251] [smartx:snapshot_refaults:22] systemd-logind.service
[47698.759663] [smartx:snapshot_refaults:22] systemtap.service
[47698.760052] [smartx:snapshot_refaults:22] virtlockd-admin.socket
[47698.760517] [smartx:snapshot_refaults:22] virtlogd-admin.socket
[47698.760927] [smartx:snapshot_refaults:22] iscsid.socket
[47698.761300] [smartx:snapshot_refaults:22] systemd-update-utmp.service
[47698.761733] [smartx:snapshot_refaults:22] dbus.socket
[47698.762094] [smartx:snapshot_refaults:22] sys-kernel-debug-tracing.mount
[47698.762549] [smartx:snapshot_refaults:22] hwclock-save.service
[47698.762949] [smartx:snapshot_refaults:22] netcf-transaction.service
[47698.763380] [smartx:snapshot_refaults:22] sysstat.service
[47698.763763] [smartx:snapshot_refaults:22] systemtap.service
[47698.764150] [smartx:snapshot_refaults:22] ovs-vswitchd.service
[47698.764559] [smartx:snapshot_refaults:22] ovs-delete-transient-ports.service
[47698.765020] [smartx:snapshot_refaults:22] network.service
[47698.765438] [smartx:snapshot_refaults:22] openvswitch.service
[47698.765836] [smartx:snapshot_refaults:22] smtx-config-hugepage.service
[47698.766271] [smartx:snapshot_refaults:22] smtx-init-cgconfig.service
[47698.766698] [smartx:snapshot_refaults:22] cgconfig.service
[47698.767086] [smartx:snapshot_refaults:22] hugepage-manager.service
[47698.767511] [smartx:snapshot_refaults:22] cloudtower-installer.service
[47698.767952] [smartx:snapshot_refaults:22] fisheye-pre-boot.service
[47698.768381] [smartx:snapshot_refaults:22] gssproxy.service
[47698.768769] [smartx:snapshot_refaults:22] iscsid.service
[47698.769144] [smartx:snapshot_refaults:22] rpc-statd-notify.service
[47698.769574] [smartx:snapshot_refaults:22] rsyslog.service
[47698.769955] [smartx:snapshot_refaults:22] sshd.service
[47698.770321] [smartx:snapshot_refaults:22] tuned.service
[47698.770696] [smartx:snapshot_refaults:22] hugepage-manager.service
[47698.771118] [smartx:snapshot_refaults:22] rpc-statd-notify.service
[47698.771545] [smartx:snapshot_refaults:22] iscsi.service
[47698.771918] [smartx:snapshot_refaults:22] kdump.service
[47698.772291] [smartx:snapshot_refaults:22] systemd-user-sessions.service
[47698.772737] [smartx:snapshot_refaults:22] iscsi.service
[47698.773110] [smartx:snapshot_refaults:22] crond.service
[47698.773486] [smartx:snapshot_refaults:22] systemd-user-sessions.service
[47698.773931] [smartx:snapshot_refaults:22] systemd-hostnamed.service
[47698.774364] [smartx:snapshot_refaults:22] run-user-0.mount
[47698.774749] [smartx:snapshot_refaults:22] kdump.service
[47698.775119] [smartx:snapshot_refaults:22] network.service
[47698.775512] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.775931] [smartx:snapshot_refaults:22] cgred.service
[47698.776302] [smartx:snapshot_refaults:22] dnf-makecache.service
[47698.776706] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.777124] [smartx:snapshot_refaults:22] systemd-tmpfiles-clean.service
[47698.777576] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.777990] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.778423] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.778833] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.779240] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.779649] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.780056] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.780514] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.780922] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.781330] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.781735] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.782135] [smartx:snapshot_refaults:22] dnf-makecache.service
[47698.782531] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.782934] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.783340] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.783739] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.784135] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.784535] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.784928] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.785316] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.785705] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.786095] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.786487] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.786873] [smartx:snapshot_refaults:22] sysstat-summary.service
[47698.787254] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.787640] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.788017] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.788410] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.788792] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.789165] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.789548] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.789916] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.790284] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.790653] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.791017] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.791392] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.791758] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.792120] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.792486] [smartx:snapshot_refaults:22] dnf-makecache.service
[47698.792834] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.793189] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.793551] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.793901] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.794251] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.794609] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.794955] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.795299] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.795655] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.795995] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.796342] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.796679] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.797016] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.797363] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.797702] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.798041] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.798392] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.798735] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.799074] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.799419] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.799762] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.800102] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.800448] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.800790] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.801124] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.801471] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.801808] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.802142] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.802482] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.802819] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.803153] [smartx:snapshot_refaults:22] dnf-makecache.service
[47698.803488] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.803829] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.804167] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.804510] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.804850] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.805186] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.805529] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.805918] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.806279] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.806661] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.807015] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.807379] [smartx:snapshot_refaults:22] sysstat-collect.service
[47698.807739] [smartx:snapshot_refaults:22] dnf-makecache.service
[47698.808075] [smartx:snapshot_refaults:22] init.scope
[47698.808367] [smartx:snapshot_refaults:22] user.slice
[47698.808696] [smartx:snapshot_refaults:22] user-0.slice
[47698.809052] [smartx:snapshot_refaults:22] user-runtime-dir@0.service
[47698.809500] [smartx:snapshot_refaults:22] user@0.service
[47698.809827] [smartx:snapshot_refaults:22] dbus.socket
[47698.810133] [smartx:snapshot_refaults:22] run-user-0.mount
[47698.810482] [smartx:snapshot_refaults:22] dev-mqueue.mount
[47698.810814] [smartx:snapshot_refaults:22] -.mount
[47698.811105] [smartx:snapshot_refaults:22] boot.mount
[47698.811426] [smartx:snapshot_refaults:22] sys-kernel-debug-tracing.mount
[47698.811822] [smartx:snapshot_refaults:22] sys-kernel-config.mount
[47698.812191] [smartx:snapshot_refaults:22] sys-fs-fuse-connections.mount
[47698.812604] [smartx:snapshot_refaults:22] var-lib-nfs-rpc_pipefs.mount
[47698.812996] [smartx:snapshot_refaults:22] dev-hugepages.mount
[47698.813370] [smartx:snapshot_refaults:22] init.scope
[47698.813687] [smartx:snapshot_refaults:22] sys-kernel-debug.mount
[47698.814060] [smartx:snapshot_refaults:22] user-runtime-dir@0.service
[47698.814496] [smartx:snapshot_refaults:22] session-1.scope
[47698.814844] [smartx:snapshot_refaults:22] session-3.scope
[47698.815188] [smartx:snapshot_refaults:22] session-4.scope
[47698.815555] [smartx:snapshot_refaults:22] session-5.scope
[47698.815903] [smartx:snapshot_refaults:22] session-31.scope
[47698.816244] [smartx:snapshot_refaults:22] session-49.scope
[47698.816589] [smartx:snapshot_refaults:22] session-53.scope
[47698.816922] [smartx:snapshot_refaults:22] session-64.scope
[47698.817257] [smartx:snapshot_refaults:22] session-68.scope
[47698.817599] [smartx:snapshot_refaults:22] session-69.scope
[47698.817933] [smartx:snapshot_refaults:22] session-80.scope
[47698.818267] [smartx:snapshot_refaults:22] session-85.scope
[47698.818604] [smartx:snapshot_refaults:22] session-109.scope
[47698.818944] [smartx:snapshot_refaults:22] session-114.scope
[47698.819284] [smartx:snapshot_refaults:22] session-123.scope
[47698.819625] [smartx:snapshot_refaults:22] session-127.scope
[47698.819965] [smartx:snapshot_refaults:22] session-129.scope
[47698.820305] [smartx:snapshot_refaults:22] session-130.scope
[47698.820647] [smartx:snapshot_refaults:22] session-131.scope
[47698.820987] [smartx:snapshot_refaults:22] session-133.scope
[47698.821333] [smartx:snapshot_refaults:22] session-134.scope
[47698.821676] [smartx:snapshot_refaults:22] session-135.scope
[47698.822018] [smartx:snapshot_refaults:22] session-138.scope
[47698.822372] [smartx:snapshot_refaults:22] session-139.scope
[47698.822718] [smartx:snapshot_refaults:22] session-141.scope
[47698.823061] [smartx:snapshot_refaults:22] test
[47698.823383] [smartx:snapshot_refaults:22] 0
[47698.823659] [smartx:snapshot_refaults:22] 1
[47698.823934] [smartx:snapshot_refaults:22] 2
[47698.824209] [smartx:snapshot_refaults:22] 3
[47698.824490] [smartx:snapshot_refaults:22] 4
[47698.824788] [smartx:snapshot_refaults:22] 5
[47698.825060] [smartx:snapshot_refaults:22] 6
[47698.825371] [smartx:snapshot_refaults:22] 7
[47698.825665] [smartx:snapshot_refaults:22] 8
[47698.825952] [smartx:snapshot_refaults:22] 9
[47698.826234] [smartx:snapshot_refaults:22] 10
[47698.826527] [smartx:snapshot_refaults:22] 11
[47698.826833] [smartx:snapshot_refaults:22] 12
[47698.827115] [smartx:snapshot_refaults:22] 13
[47698.827402] [smartx:snapshot_refaults:22] 14
[47698.827680] [smartx:snapshot_refaults:22] 15
[47698.827957] [smartx:snapshot_refaults:22] 16
[47698.828234] [smartx:snapshot_refaults:22] 17
[47698.828515] [smartx:snapshot_refaults:22] 18
[47698.828791] [smartx:snapshot_refaults:22] 19
[47698.829057] [smartx:snapshot_refaults:22] 20
[47698.829347] [smartx:snapshot_refaults:22] 21
[47698.829619] [smartx:snapshot_refaults:22] 22
[47698.829876] [smartx:snapshot_refaults:22] 23
[47698.830130] [smartx:snapshot_refaults:22] 24
```
