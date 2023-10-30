#pragma once
#ifndef ANIMATOR_C
#define ANIMATOR_C

#include "animator.h"

void play_animation(
    Vector2 pos,
    Texture texture,
    float horisontal_count_frames,
    float vertical_count_frames
) {
    int current_frame, frame_counter, frame_speed = 8;
    Rectangle frame_rect = (Rectangle) {
        0.0f,
        0.0f,
        texture.width / horisontal_count_frames,
        texture.height / vertical_count_frames
    };

    frame_counter++;
    if (frame_counter >= (60/frame_speed)) {
        frame_counter = 0;
        current_frame++;
        if (current_frame > horisontal_count_frames)
            current_frame = 0;
        frame_rect.x = 
            (float) current_frame * 
            texture.width/horisontal_count_frames;
        frame_rect.y = current_frame *
            texture.height/vertical_count_frames; 
    }

    DrawTextureRec(
        texture,
        frame_rect,
        pos,
        WHITE
    );
}

#endif