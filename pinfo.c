/******************************
 * Filename: pinfo.c
 * Description: Part 2.1 of lab 9
 * Author: Charlie Lemerand
 * Section: CPE2600 121
 * Date: 10/31/2025
 * Compile: make
******************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <sys/resource.h>

int main(int argc, char* argv[])
{
    pid_t pid;
    if(argc > 1){
        sscanf(argv[1], "%d", &pid);
    } else {
        pid = getpid();
    }

    int priority = getpriority(PRIO_PROCESS, pid);
    if(priority == -1){
        printf("Cannot get PID priority");
        return 0;
    }

    int policy = sched_getscheduler(pid);
    if(policy == -1){
        printf("Cannot get scheduler");
        return 0;
    }


    printf("PID: %d\n", pid);
    printf("Priority: %d\n", priority);
    switch(policy){
        case SCHED_OTHER: {
            printf("Schedule: SCHED_OTHER\n");
            break;
        }
        case SCHED_FIFO: {
            printf("Schedule: SCHED_FIFO");
            break;
        }
        case SCHED_RR: {
            printf("Schedule: SCHED_RR");
            break;
        }
        case SCHED_BATCH: {
            printf("Schedule: SCHED_BATCH");
            break;
        }
        case SCHED_IDLE: {
            printf("Schedule: SCHED_IDLE");
            break;
        }
        case SCHED_DEADLINE: {
            printf("Schedule: SCHED_DEADLINE");
            break;
        }
        default: {
            printf("Schedule: Unknown");
            break;
        }
    }

    return 0;
}