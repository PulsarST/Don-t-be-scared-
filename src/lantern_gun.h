#pragma once
#ifndef LANTERN_GUN_H
#define LANTERN_GUN_H

#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

#include "LOG.h"

typedef struct {
    Texture texture;
    Vector2 pos;
    float lantern_angle;
    float reloading;
} Lantern_gun;

Lantern_gun *create_lantern(
    const char *filename,
    float x,
    float y,
    float reloading
);

void draw_lantern(Lantern_gun *lantern);
void switch_light(Lantern_gun *lantern);
void destroy_lantern(Lantern_gun *lantern);

#endif