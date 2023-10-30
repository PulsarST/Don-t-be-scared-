#pragma once
#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <raylib.h>

void play_animation(
    Vector2 pos,
    Texture texture,
    float horisontal_count_frames,
    float vertical_count_frames
);

#endif