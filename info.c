/******************************
 * Filename: finfo.c
 * Description: Part 3 of lab 9
 * Author: Charlie Lemerand
 * Section: CPE2600 121
 * Date: 11/3/2025
 * Compile: make
******************************/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <unistd.h>


int main(int argc, char* argv[])
{
    //prints current time of day in nanoseconds and readable time
    struct timespec time;
    struct tm *printTime;
    if(clock_gettime(CLOCK_REALTIME, &time)== 0 ){
        printTime = localtime(&time.tv_sec);

        long int time_nsec= (time.tv_sec%(3600*24))*100000000+time.tv_nsec;
        printf("%s", asctime(printTime));
        printf("Today's time in nanosecods: %ld\n", time_nsec);
    } 

    //prints the network name
    char hostname[100];
    if(gethostname(hostname, sizeof(hostname))== 0){
        printf("Host Name: %s", hostname);
    }

    //prints the system name, release, version, and machine info
    struct utsname sinfo;
    if(uname(&sinfo) == 0){
        printf("Operating system name: %s\n", sinfo.sysname);
        printf("Operating system release: %s\n", sinfo.release);
        printf("Operating system version: %s\n", sinfo.version);
        printf("Operating system hardware: %s\n", sinfo.machine);
    }

    //prints the number of CPU's
    printf("Num of CPU: %d\n", get_nprocs());


    //prints the total amound of memory and also the amound of free memory
    long size = getpagesize();
    long pages = sysconf(_SC_PHYS_PAGES);
    long free = sysconf(_SC_AVPHYS_PAGES);
    if(size!= 0 && pages!= 0){
        printf("Total memory in bytes: %ld\n", size * pages);
    }

    
    if(size!= 0 && free!= 0){
        printf("Free memory in bytes: %ld\n", size * free);
    }


    return 0;
}