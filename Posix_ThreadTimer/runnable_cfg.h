//
// Created by redmk on 2022-10-30.
//

#ifndef POSIX_TIMER_CREATE_RUNNABLE_CFG_H
#define POSIX_TIMER_CREATE_RUNNABLE_CFG_H

#define RUNNABLE_MAX_COUNT              5
#define RUNNABLE_MAX_CALLBACK_COUNT     10

typedef enum runnable_callback_type{
    HANDLER_100MS,
    HANDLER_200MS,
    HANDLER_300MS,
    HANDLER_500MS,
    HANDLER_1000MS
}callback_type_t;

#endif //POSIX_TIMER_CREATE_RUNNABLE_CFG_H
