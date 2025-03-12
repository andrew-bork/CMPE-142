


obj-m += simple.o

all: bin/file_copy
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/simple modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/simple clean