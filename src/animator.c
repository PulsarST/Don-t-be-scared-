#ifndef ANIMATOR_C
#define ANIMATOR_C

#include "animator.h"

Animation_sprite *create_sprite(
    Texture texture,
    Vector2 *pos,
    int collumns,
    int rows,
    float speed
) {
    Rectangle rect = (Rectangle) {
        0.0f, 0.0f,
        (float)texture.width/collumns,
        (float)texture.height/rows
    };

    Animation_sprite *sprite = malloc(
        sizeof(Animation_sprite));
    sprite->pos = pos;
    sprite->texture = texture;
    sprite->rect = rect;
    sprite->current_frame_x = 0;
    sprite->current_frame_y = 0;
    sprite->collumns = collumns;
    sprite->rows = rows;
    sprite->speed = speed;

    return sprite;
}

void play_animation_pro(
    Animation_sprite *sprite, int anim_num) {
    static int frame_counter;

    sprite->rect.x =
        sprite->current_frame_x * sprite->rect.width;
    sprite->rect.y =
        sprite->current_frame_y * sprite->rect.height;

    frame_counter++;
    if (frame_counter >= 60.0f/sprite->speed) {
        frame_counter = 0;
        sprite->current_frame_x++;
        sprite->current_frame_y = anim_num;
        if (sprite->current_frame_x > sprite->collumns)
            sprite->current_frame_x = 0;
        if (sprite->current_frame_y > sprite->rows)
            sprite->current_frame_y = 0;
    }
    
    DrawTextureRec(
        sprite->texture,
        sprite->rect,
        *sprite->pos,
        WHITE);
}

void destroy_sprite(Animation_sprite *sprite) {
    UnloadTexture(sprite->texture);
    free(sprite);
}

#endif