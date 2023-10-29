#pragma once
#ifndef AABB_H
#define AABB_H

#include <stdbool.h>
#include <raylib.h>

typedef struct {
    int min_x, min_y;
    int max_x, max_y;
} AABB;

bool collide_aabb(AABB a, AABB b);
bool collide_point(AABB a, int point_x, int point_y);
bool collide_point_v(AABB a, Vector2 point);

#endif