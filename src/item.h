#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <raylib.h>
#include "AABB.h"

typedef struct {
    Texture texture;
    Vector2 pos;
    AABB collider;
} Item;

Item *create_item(
    Texture texture,
    float x,
    float y
);

void draw_item(Item *item);
void destroy_item(Item *item);

#endif