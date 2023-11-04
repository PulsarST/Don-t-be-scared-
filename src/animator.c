#pragma once
#ifndef ANIMATOR_C
#define ANIMATOR_C

#include "animator.h"

Animation_sprite create_sprite(
    Texture texture,
    Vector2 *pos,
    int collumns,
    int rows
) {
    Rectangle rect = (Rectangle) {
        0.0f, 0.0f,
        (float)texture.width/collumns,
        (float)texture.height/rows
    };
    return (Animation_sprite) {
        texture,pos,
        rect, collumns,
        rows
    };
}

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

void play_animation_pro(
    Animation_sprite sprite, int anim_num) {
    static int
        frameX = 0,
        frameY = 0,
        frame_counter,
        frame_speed = 5;

    sprite.rect.x = frameX * sprite.rect.width;
    sprite.rect.y = frameY * sprite.rect.height;

    frame_counter++;
    if (frame_counter >= 60.0f/frame_speed) {
        frame_counter = 0;
        frameX++; frameY = anim_num;
        if (frameX > sprite.collumns) frameX = 0;
        if (frameY > sprite.rows) frameY = 0;
    }
    DrawTextureRec(
        sprite.texture,
        sprite.rect,
        *sprite.pos,
        WHITE);
}

#endif