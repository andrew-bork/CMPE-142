
.PHONY: clean all

all: bin/file_copy

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