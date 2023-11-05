#ifndef LEVEL_C
#define LEVEL_C

#include "level.h"

Levels create_level(
    const char *filename,
    float x,
    float y
) {
    Levels levels = { 0 };
    Image img = LoadImage(filename);
    ImageResize(
        &img,
        img.width * 3,
        img.height * 3);
    levels.texture = LoadTextureFromImage(img);
    UnloadImage(img);
    levels.pos = (Vector2) {x, y};

    return levels;
}

void draw_level(Levels levels) {
    DrawTexture(
        levels.texture,
        levels.pos.x,
        levels.pos.y,
        WHITE);
}

void destroy_level(Levels levels) {
    UnloadTexture(levels.texture);
}

#endif