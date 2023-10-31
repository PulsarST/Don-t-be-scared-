#pragma once
#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdlib.h>

#define ASSERT(_v, ...) if (!(_v)) __VA_ARGS__; exit(1);

#endif