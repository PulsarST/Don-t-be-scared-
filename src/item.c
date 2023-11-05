#ifndef ITEM_C
#define ITEM_C

#include "item.h"

Item *create_item(
    Texture texture,
    float x,
    float y
) { 
    Item *item = malloc(sizeof(Item));
    item->pos = (Vector2) {x, y};
    item->texture = texture;
    item->collider = (AABB) {
        item->pos.x, item->pos.y,
        item->pos.x + texture.width,
        item->pos.y + texture.height
    };
    return item;
}

void draw_item(Item *item) {
    DrawTexture(
        item->texture,
        item->pos.x,
        item->pos.y,
        WHITE);

    update_aabb(
        &item->collider,
        item->pos.x,
        item->pos.y,
        item->texture.width,
        item->texture.height);
}

void destroy_item(Item *item) {
    UnloadTexture(item->texture);
    free(item);
}

#endif