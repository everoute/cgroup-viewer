obj-m += cg.o

all:
	make -C /lib/modules/$(kernel)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(kernel)/build M=$(PWD) clean
