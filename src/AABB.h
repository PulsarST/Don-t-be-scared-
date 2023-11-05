#ifndef AABB_H
#define AABB_H

#include <stdbool.h>
#include <raylib.h>

#include "utils/Colors.h"

typedef struct {
    int min_x, min_y;
    int max_x, max_y;
} AABB;

typedef struct {
    Vector2 pos;
    float radius;
} Circle_aabb;

void update_aabb(
    AABB *aabb,
    float x,
    float y,
    float width,
    float height);

void update_circle_aabb(
    Circle_aabb *aabb,
    float x,
    float y,
    float radius);

void draw_circle_aabb(Circle_aabb aabb);
bool collide_aabb(AABB a, AABB b);
bool collide_point(AABB a, int point_x, int point_y);
bool collide_point_v(AABB a, Vector2 point);

bool collide_circle_aabb(AABB a, Circle_aabb b);

#endif
