#ifndef AABB_C
#define AABB_C

#include "AABB.h"

void update_aabb(
    AABB *aabb,
    float x,
    float y,
    float width,
    float height
) {
    aabb->min_x = x;
    aabb->min_y = y;
    aabb->max_x = x + width;
    aabb->max_y = y + height;
}

void update_circle_aabb(
    Circle_aabb *aabb,
    float x,
    float y,
    float radius
) {
    aabb->pos = (Vector2) {x, y};
    aabb->radius = radius;
}

void draw_circle_aabb(Circle_aabb aabb) {
    DrawCircle(
        aabb.pos.x,
        aabb.pos.y,
        aabb.radius,
        LIGHT_WHITE);
}


bool collide_aabb(AABB a, AABB b) {
    return
        a.min_x <= b.max_x && a.max_x >= b.min_x &&
        a.min_y <= b.max_y && a.max_y >= b.min_y;
}

bool collide_point(AABB a, int point_x, int point_y) {
    return 
        a.min_x <= point_x && a.max_x >= point_x &&
        a.min_y <= point_y && a.max_y >= point_y;
}

bool collide_point_v(AABB a, Vector2 point) {
    return
        a.min_x <= point.x && a.max_x >= point.x &&
        a.min_y <= point.y && a.max_y >= point.y;
}

bool collide_circle_aabb(AABB a, Circle_aabb b) {
    return
        a.min_x <= b.pos.x + b.radius &&
        a.max_x >= b.pos.x - b.radius &&
        a.min_y <= b.pos.y + b.radius &&
        a.max_x >= b.pos.y - b.radius;
}


#endif