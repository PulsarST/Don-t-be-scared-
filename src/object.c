#ifndef OBJECT_C
#define OBJECT_C

#include "object.h"

Object create_object(
    float x,
    float y,
    const char *filename,
    Type type
) {
    Object obj = { 0 };
    obj.pos = (Vector2) {x, y};
    Image img = LoadImage(filename);
    ImageResize(
        &img,
        img.width * 1.5,
        img.height * 1.5);
    obj.texture = LoadTextureFromImage(img);
    UnloadImage(img);
    obj.collider = (AABB) {
        obj.pos.x, obj.pos.y,
        obj.pos.x + obj.texture.width,
        obj.pos.y + obj.texture.height
    };

    return obj;
}

void draw_object(Object obj) {
    DrawTexture(
        obj.texture,
        obj.pos.x,
        obj.pos.y,
        WHITE);
}

void move_object(Object obj) {
    update_aabb(
        &obj.collider,
        obj.pos.x,
        obj.pos.y,
        obj.texture.width,
        obj.texture.height);
}

void destroy_object(Object obj) {
    UnloadTexture(obj.texture);
}


#endif