#pragma once
#ifndef ANIMATOR_C
#define ANIMATOR_C

#include "animator.h"

void play_animation(
    Texture texture,
    Vector2 pos,
    bool play_anim,
    int number_of_anim,
    float collumns,
    float rows
) {
    static int
        frameX = 0,
        frameY = 0,
        frame_counter,
        frame_speed = 17;

    Rectangle frame_rect = (Rectangle) {
        frameX * (texture.width/collumns),
        frameY * (texture.height/rows),
        texture.width/collumns,
        texture.height/rows
    };

    if (play_anim) frame_counter++;
    if (frame_counter >= 60.0f/frame_speed) {
        frame_counter = 0;
        frameX++; frameY = number_of_anim;
        if (frameX > collumns) frameX = 0;
        if (frameY > rows) frameY = 0;
        frame_rect.x = frameX * (texture.width/collumns);
        frame_rect.y = frameY * (texture.height/rows);
    }

    DrawTextureRec(
        texture,
        frame_rect,
        pos,
        WHITE
    );
}

#endif