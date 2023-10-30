#include "player.h"

Player *create_player(
    float x,float y, float speed, const char* filename
) {
    Player *player = malloc(sizeof(Player));
    player->pos = (Vector2) {x, y}; 
    player->dir = (Vector2) {0.0f, 0.0f};
    player->speed = speed;
    player->texture = LoadTexture(filename);
    player->collider = (AABB) {
        x,y,
        player->texture.width,
        player->texture.height
    };

    return player;
}

static void move(Player *player, float deltatime) {
    player->pos.x = (
        player->dir.x * player->speed * deltatime
    );

    player->pos.y = (
        player->dir.y * player->speed * deltatime
    );
}

void update_player(Player *player, float deltatime) {
    move(player, deltatime);
}

void draw_player(Player *player) {
    if (player->dir.x == 1) {
        play_animation(
            player->pos,
            player->texture,
            4,
            1
        );
    } else if (player->dir.x == -1) {
        play_animation(
            player->pos,
            player->texture,
            4,
            2
        );
    } else {
        play_animation(
            player->pos,
            player->texture,
            1,
            1
        );
    }    
}

void destroy_player(Player *player) {
    UnloadTexture(player->texture);
    free(player);
}
