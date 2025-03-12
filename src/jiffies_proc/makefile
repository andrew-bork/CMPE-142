
.PHONY: clean all

obj-m += jiffies.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/jiffies_proc modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/jiffies_proc clean