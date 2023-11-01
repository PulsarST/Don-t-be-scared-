#pragma once
#ifndef LANTERN_GUN_C
#define LANTERN_GUN_C

#include "lantern_gun.h"

Lantern_gun *create_lantern(
    const char *filename,
    float x,
    float y,
    float reloading
) {
    Lantern_gun *lantern = 
        malloc(sizeof(Lantern_gun));

    ASSERT(lantern != NULL, "lantern isn't loaded");
    lantern->texture = LoadTexture(filename);
    lantern->pos = (Vector2) {x, y};
    lantern->lantern_angle = 0.0f;
    lantern->reloading = reloading;

    return lantern;
}

void draw_lantern(Lantern_gun *lantern) {
    DrawTextureEx(
        lantern->texture,
        lantern->pos,
        lantern->lantern_angle,
        4.0f,
        WHITE
    );
}

void switch_light(Lantern_gun *lantern) {
    Rectangle rect_light = (Rectangle) {
        lantern->pos.x + lantern->texture.width,
        lantern->pos.y,
        10000,
        lantern->texture.height
    };

    printf("x: %f\ny: %f\nwidth: %f\nheight: %f\n",
        rect_light.x, rect_light.y,
        rect_light.width, rect_light.height
    );

    DrawRectanglePro(
        rect_light,
        (Vector2) {0.0f, 0.0f},
        lantern->lantern_angle,
        WHITE
    );
    INFO("light is turn on");
}

void destroy_lantern(Lantern_gun *lantern) {
    UnloadTexture(lantern->texture);
    free(lantern);
}

#endif
