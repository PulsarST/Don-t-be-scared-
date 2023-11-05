#include "player.h"

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
        4, 8, 7.0f);
    player->collider = (AABB) {
        x,y,
        x + player->sprite->rect.width,
        y + player->sprite->rect.height
    };

    return player;
}

void move(Player *player, const float deltatime) {
    Vector2 normalized_vector =
        Vector2Normalize(player->dir);
    player->pos.x +=
        normalized_vector.x * player->speed * deltatime;
    player->pos.y +=
        normalized_vector.y * player->speed * deltatime;
}

void update_player(
    Player *player, const float deltatime
) {
    move(player, deltatime);
    update_aabb(
        &player->collider,
        player->pos.x,
        player->pos.y,
        (float) player->sprite->texture.width
        / player->sprite->collumns,
        (float) player->sprite->texture.height
        / player->sprite->rows);
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

void add_item(Player *player, Item *item) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (player->items[i] == NULL) {
            player->items[i] = item;
        }
    }
}

void destroy_player(Player *player) {
    destroy_sprite(player->sprite);
    free(player);
}
