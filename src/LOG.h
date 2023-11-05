#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdlib.h>

#define ASSERT(_v, message) if (!(_v))          \
    printf(                                     \
        "\e[0;31m[%s]: %s\e[0;37m\n",           \
        __FILE__,                               \
        message                                 \
    )

#define INFO(message)                       \
    printf("\e[0;34m[%s]: %s\e[0;37m\n",    \
    __FILE__, message)                      \

#endif