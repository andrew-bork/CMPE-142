
.PHONY: clean

bin/file_copy: src/file_copy/file_copy.c bin
	gcc src/file_copy/file_copy.c -o $@

bin:
	mkdir bin

build:
	mkdir build





clean:
	rm -rf build
nuke:
	rm -rf build
	rm -rf bin

