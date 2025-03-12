


obj-m += jiffies.o

all: bin/file_copy
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/jiffies modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/jiffies clean