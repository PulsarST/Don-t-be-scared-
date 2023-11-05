#ifndef OBJECT_H
#define OBJECT_H

#include <raylib.h>

#include "AABB.h"

typedef enum {
    Kinematic = 0,
    Static    = 1
} Type;

typedef struct {
    Vector2 pos;
    Texture texture;
    AABB collider;
    Type type;
} Object;

Object create_object(
    float x,
    float y,
    const char *filename,
    Type type);

void draw_object(Object obj);
void move_object(Object obj);
void destroy_object(Object obj);

#endif