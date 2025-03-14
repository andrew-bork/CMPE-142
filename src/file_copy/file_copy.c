#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


// size_t BLOCK_SIZE = 4096; // 4kb
#define BLOCK_SIZE 4096


int main(int argc, char ** argv) {

    if(argc < 3) {
        fprintf(stderr, "Source or Desitination file not specified\n");
        return -1;
    }

    char * source_filename = argv[1];
    char * destination_filename = argv[2];

    int source_fd = open(source_filename, O_RDONLY);
    if(source_fd < 0) {
        fprintf(stderr, "Source file could not be opened.\n");
        return -1;
    }
    int destination_fd = open(destination_filename, O_CREAT | O_WRONLY, 0666);
    if(destination_fd < 0) {
        fprintf(stderr, "Destination file could not be opened.\n");
        close(source_fd);
        return -1;
    }

    char buf[BLOCK_SIZE];

    int has_more = 1;
    while(has_more) {
        int amt_read = read(source_fd, buf, BLOCK_SIZE);
        // printf("%s\n", buf);
        if(amt_read < 0){
            fprintf(stderr, "Something went wrong with reading.\n");
            close(source_fd);
            close(destination_fd);
            return -1;
        }
        if(amt_read < BLOCK_SIZE) {
            has_more = 0;
        }
        int amt_written = write(destination_fd, buf, amt_read);
        if(amt_written != amt_read) {
            fprintf(stderr, "Something went wrong with writing.\n");
            close(source_fd);
            close(destination_fd);
            return -1;
        }
    }

    close(source_fd);
    close(destination_fd);
}