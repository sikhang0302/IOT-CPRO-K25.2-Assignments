#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <libgen.h> 

int main(int argc, char *argv[]) {
    if (!(argc == 2)) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *file_path = argv[1];
    struct stat file_stat;

    // lstat() returns -1 if file does not exist or can not access
    if (lstat(file_path, &file_stat) == -1) {
        // Print the error message and exit
        perror("Error getting file information");
        exit(EXIT_FAILURE);
    }

    // Get file path
    printf("- File path:\n    %s\n", file_path);

    // Get type of file
    printf("- File Type:\n    ");

    if (S_ISBLK(file_stat.st_mode)) {
        printf("Block Device\n");
    }
    else if (S_ISCHR(file_stat.st_mode)) {
        printf("Character Device\n");
    }
    else if (S_ISFIFO(file_stat.st_mode)) {
        printf("FIFO/Pipe\n");
    }
    else if (S_ISREG(file_stat.st_mode)) {
        printf("Regular File\n");
    }
    else if (S_ISDIR(file_stat.st_mode)) {
        printf("Directory\n");
    }
    else if (S_ISLNK(file_stat.st_mode)) {
        printf("Symbolic Link\n");
    }
    else if (S_ISSOCK(file_stat.st_mode)) {
        printf("Socket\n");
    }
    else {
        printf("Unknow type of file\n");
    } 
    
    // Get size of file
    printf("- Size:\n    %jd bytes\n",(intmax_t)file_stat.st_size);

    // Get time of last data modification
    printf("- Last Modified:\n    %s", (ctime)(&file_stat.st_mtime));

    return 0;
}
