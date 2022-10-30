//
// Created by redmk on 2022-10-29.
//

#include "runnable.h"

void p_func_1000(void) {
    pid_t pid; //process id
    pthread_t tid; // thread id

    pid = getpid(); //4
    tid = pthread_self();

    (void)printf("RUNNABLE_1000MS\n");
    (void)printf("thread name : tid : %x, pid : %u\n", (unsigned int) tid, (unsigned int) pid); //5
}

void p_func_500(void) {
    pid_t pid; //process id
    pthread_t tid; // thread id

    pid = getpid(); //4
    tid = pthread_self();

    (void)printf("RUNNABLE_500MS\n");
    (void)printf("thread name : tid : %x, pid : %u\n", (unsigned int) tid, (unsigned int) pid); //5
}

void p_func_100(void) {
    pid_t pid; //process id
    pthread_t tid; // thread id

    pid = getpid(); //4
    tid = pthread_self();

    (void)printf("RUNNABLE_100MS\n");
    (void)printf("thread name : tid : %x, pid : %u\n", (unsigned int) tid, (unsigned int) pid); //5
}

int main(void) {

    add_runnable_callback(HANDLER_100MS, p_func_100);
    add_runnable_callback(HANDLER_500MS, p_func_500);
    add_runnable_callback(HANDLER_1000MS, p_func_1000);

    runnable_start();

    for(;;);

    return 0;
}