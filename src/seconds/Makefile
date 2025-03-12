


obj-m += seconds.o

all: bin/file_copy
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/seconds modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/seconds clean