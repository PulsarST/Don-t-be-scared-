#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <stdlib.h>
#include <stdbool.h>
#include <raylib.h>

typedef struct {
    Texture texture;
    Vector2 *pos;
    Rectangle rect;
    int current_frame_x;
    int current_frame_y;
    int collumns;
    int rows;
    float speed;
} Animation_sprite;

Animation_sprite *create_sprite(
    Texture texture,
    Vector2 *pos,
    int collumns,
    int rows,
    float speed);
void play_animation_pro(
    Animation_sprite *sprite, int anim_num);

void destroy_sprite(Animation_sprite *sprite);

#endif
