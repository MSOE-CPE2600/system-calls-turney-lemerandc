/******************************
 * Filename: pmod.c
 * Description: Part 2.2 of lab 9
 * Author: Charlie Lemerand
 * Section: CPE2600 121
 * Date: 11/3/2025
 * Compile: make
******************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <time.h>

int main(int argc, char* argv[])
{
    int nicenum = nice(10);
    if(nicenum == -1){
        printf("Nice did not change");
    } else {
        printf("Nice value : %d\n", nicenum);
    }

    struct timespec nanoNum= {1, 837272638};
    nanosleep(&nanoNum, NULL);

    printf("goodbye\n");

    return 0;
}