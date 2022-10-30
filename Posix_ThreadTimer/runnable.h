//
// Created by redmk on 2022-10-30.
//

#ifndef POSIX_TIMER_CREATE_RUNNABLE_H
#define POSIX_TIMER_CREATE_RUNNABLE_H

#include "runnable_cfg.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


typedef void (*runnable_callback_t)(void);

void runnable_start(void);

void add_runnable_callback(callback_type_t runnableType, runnable_callback_t func);

_Noreturn void* runnable_0_100ms(void *data);
_Noreturn void* runnable_0_200ms(void *data);
_Noreturn void* runnable_0_300ms(void *data);
_Noreturn void* runnable_0_500ms(void *data);
_Noreturn void* runnable_0_1000ms(void *data);


#endif //POSIX_TIMER_CREATE_RUNNABLE_H
