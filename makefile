
.PHONY: clean all

obj-m += jiffies.o seconds.o simple.o

all: bin/file_copy
    echo make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/jiffies_proc modules
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/simple modules
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src/seconds modules
clean:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/src clean
bin:
	mkdir bin

build:
	mkdir build


bin/file_copy: src/file_copy.c bin
	gcc src/file_copy.c -o $@





clean:
	rm -rf build
nuke:
	rm -rf build
	rm -rf bin