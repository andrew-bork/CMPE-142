


obj-m += jiffies.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/jiffies modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/jiffies clean