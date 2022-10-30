//
// Created by redmk on 2022-10-30.
//

#include "runnable.h"
#include "stdbool.h"

#define SLEEP_TIME_100MS                    100000U
#define SLEEP_TIME_200MS                    200000U
#define SLEEP_TIME_300MS                    300000U
#define SLEEP_TIME_500MS                    500000U
#define SLEEP_TIME_1000MS                   1000000U

typedef void *(*runnable_t)(void *data);

typedef struct runnable_param {
    runnable_callback_t callback[RUNNABLE_MAX_CALLBACK_COUNT];
    unsigned char count;
} runnable_param_t;

static pthread_t pthreadList[RUNNABLE_MAX_COUNT];

static runnable_t runnableList[RUNNABLE_MAX_COUNT] = {
        runnable_0_100ms,
        runnable_0_200ms,
        runnable_0_300ms,
        runnable_0_500ms,
        runnable_0_1000ms,
};

static int threadIdList[RUNNABLE_MAX_COUNT];

static runnable_param_t *runnableParamHeader;
static runnable_param_t runnableParam[RUNNABLE_MAX_COUNT];

int status;

void runnable_start(void) {

    runnableParamHeader = runnableParam;

    for (int i = 0; i < RUNNABLE_MAX_COUNT; i++) {

        threadIdList[i] = pthread_create(&pthreadList[i],
                                         NULL,
                                         runnableList[i],
                                         (void*)runnableParamHeader
                                         );
    }
}

void add_runnable_callback(callback_type_t runnableType, runnable_callback_t func) {
    if(runnableParam[runnableType].count >= RUNNABLE_MAX_COUNT - 1){
        (void)printf("full runnable callback\n");
    }
    else{
        runnableParam[runnableType].callback[runnableParam[runnableType].count] = func;
        runnableParam[runnableType].count++;
    }
}

_Noreturn void* runnable_0_100ms(void *data) {
    runnable_param_t* ctx = (runnable_param_t*)data;

    while (true) {
        (void) usleep(SLEEP_TIME_100MS);
        for (int i = 0; i < ctx[HANDLER_100MS].count; i++) {
            ctx[HANDLER_100MS].callback[i]();
        }
    }
}

_Noreturn void* runnable_0_200ms(void *data) {
    runnable_param_t* ctx = (runnable_param_t*)data;

    while (true) {
        (void) usleep(SLEEP_TIME_200MS);
        for (int i = 0; i < ctx[HANDLER_200MS].count; i++) {
            ctx[HANDLER_200MS].callback[i]();
        }
    }
}

_Noreturn void* runnable_0_300ms(void *data) {
    runnable_param_t* ctx = (runnable_param_t*)data;

    while (true) {
        (void) usleep(SLEEP_TIME_300MS);
        for (int i = 0; i < ctx[HANDLER_300MS].count; i++) {
            ctx[HANDLER_300MS].callback[i]();
        }
    }
}

_Noreturn void* runnable_0_500ms(void *data) {
    runnable_param_t* ctx = (runnable_param_t*)data;

    while (true) {
        (void) usleep(SLEEP_TIME_500MS);
        for (int i = 0; i < ctx[HANDLER_500MS].count; i++) {
            ctx[HANDLER_500MS].callback[i]();
        }
    }
}

_Noreturn void* runnable_0_1000ms(void *data) {
    runnable_param_t* ctx = (runnable_param_t*)data;

    while (true) {
        (void) usleep(SLEEP_TIME_1000MS);
        for (int i = 0; i < ctx[HANDLER_1000MS].count; i++) {
            ctx[HANDLER_1000MS].callback[i]();
        }
    }
}