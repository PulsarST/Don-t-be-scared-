#pragma once
#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <stdbool.h>
#include <raylib.h>

void play_animation(
    Texture texture,
    Vector2 pos,
    bool play_anim,
    int number_of_anim,
    float collumns,
    float rows
);

#endif
