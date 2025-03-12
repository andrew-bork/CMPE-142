
.PHONY: clean all

all: bin/file_copy

bin:
	mkdir bin

build:
	mkdir build


bin/file_copy: src/file_copy.c bin
	gcc src/file_copy.c -o $@



obj-m += dvt-driver.o

all:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/seconds modules
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/jiffies_proc modules
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/simple modules
clean:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/seconds clean
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/jiffies_proc clean
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/simple clean


clean:
	rm -rf build
nuke:
	rm -rf build
	rm -rf bin