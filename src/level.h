#ifndef LEVEL_H
#define LEVEL_H

#include <raylib.h>

typedef struct {
    Texture texture;
    Vector2 pos;
} Levels;

Levels create_level(
    const char *filename,
    float x,
    float y);

void draw_level(Levels levels);
void destroy_level(Levels levels);

#endif