obj-m += cg.o

kernel=$(shell uname -r)
$(info $(kernel))
all:
	make -C /lib/modules/$(kernel)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(kernel)/build M=$(PWD) clean
