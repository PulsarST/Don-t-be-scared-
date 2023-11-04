#include "player.h"
#include <stdbool.h>
#include <stdio.h>

Player *create_player(
    float x,
    float y,
    float speed,
    const char* filename
) {
    Player *player = malloc(sizeof(Player));
    ASSERT(player != NULL, "player isn't loaded");
    player->pos = (Vector2) {x, y}; 
    player->dir = Vector2Zero();
    player->speed = speed;
    player->sprite = create_sprite(
        LoadTexture(filename),
        &player->pos,
        4, 8);
    player->collider = (AABB) {
        x,y,
        x + player->sprite.rect.width,
        y + player->sprite.rect.height
    };

    return player;
}

void move(Player *player, const float deltatime) {
    Vector2Normalize(player->dir);
    player->pos.x +=
        player->dir.x * player->speed * deltatime;
    player->pos.y +=
        player->dir.y * player->speed * deltatime;
}

void update_player(
    Player *player, const float deltatime
) {
    move(player, deltatime);
}

void draw_player(Player *player) {
    int anim_row = 0;
    static int tmp_anim_row = 1;
    if (player->dir.x > 0) {
        anim_row = 0;
        tmp_anim_row = 1;
    } else if (player->dir.x < 0) {
        anim_row = 2;
        tmp_anim_row = 3;
    } else if (player->dir.y > 0) {
        anim_row = 4;
        tmp_anim_row = 5;
    } else if (player->dir.y < 0) {
        anim_row = 6;
        tmp_anim_row = 7;
    } else anim_row = tmp_anim_row;
    play_animation_pro(
        player->sprite,
        anim_row);
}

void destroy_player(Player *player) {
    UnloadTexture(player->sprite.texture);
    free(player);
}
