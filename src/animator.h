#pragma once
#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <stdbool.h>
#include <raylib.h>

typedef struct {
    Texture texture;
    Vector2 *pos;
    Rectangle rect;
    int collumns;
    int rows;
} Animation_sprite;

void play_animation(
    Texture texture,
    Vector2 pos,
    bool play_anim,
    int number_of_anim,
    float collumns,
    float rows
);

Animation_sprite create_sprite(
    Texture texture, Vector2 *pos, int collumns, int rows);
void play_animation_pro(
    Animation_sprite sprite, int anim_num);

#endif
