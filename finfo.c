/******************************
 * Filename: finfo.c
 * Description: Part 3 of lab 9
 * Author: Charlie Lemerand
 * Section: CPE2600 121
 * Date: 11/3/2025
 * Compile: make
******************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Usage: ./finfo <filename>\n");
        return 1;
    }

    const char *filename = argv[1];
    struct stat fileinfo;

    if (stat(filename, &fileinfo) == -1) {
        printf("Error with stat");
        return 1;
    }

    // --- Determine file type ---
    printf("File: %s\n", filename);
    printf("Type: ");
    if (S_ISREG(fileinfo.st_mode)){
        printf("Regular file\n");
    } else if (S_ISDIR(fileinfo.st_mode)){
        printf("Directory\n");
    } else if (S_ISLNK(fileinfo.st_mode)) {
        printf("Symbolic link\n");
    } else if (S_ISCHR(fileinfo.st_mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(fileinfo.st_mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(fileinfo.st_mode)) {
        printf("FIFO (pipe)\n");
    } else if (S_ISSOCK(fileinfo.st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown\n");
    }

    //prints permissions
    printf("Permissions: ");
    printf( (fileinfo.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileinfo.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileinfo.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileinfo.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileinfo.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileinfo.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileinfo.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileinfo.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileinfo.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    //prints owner UID
    printf("Owner UID: %d\n", fileinfo.st_uid);

    //prints size in bytes
    printf("Size: %ld bytes\n", fileinfo.st_size);

    //prints last modification time (formatted)
    struct tm *modTime = localtime(&fileinfo.st_mtime);
    if (modTime != NULL) {
        printf("Last changed at: %s", asctime(modTime));
    }

    return 0;
}
