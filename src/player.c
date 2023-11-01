#include "player.h"

Player *create_player(
    float x,
    float y,
    float speed,
    const char* filename
) {
    Player *player = malloc(sizeof(Player));
    ASSERT(player != NULL, "player isn't loaded")
    player->pos = (Vector2) {x, y}; 
    player->dir = (Vector2) {0.0f, 0.0f};
    player->speed = speed;
    player->texture = LoadTexture(filename);
    player->collider = (AABB) {
        x,y,
        player->texture.width,
        player->texture.height
    };

    player->lantern = create_lantern(
        "..\\res\\lantern.png",
        player->pos.x + (player->texture.width / 8.0f),
        player->pos.y + (player->texture.height / 8.0f),
        1.5f
    );

    return player;
}

void move(Player *player, const float deltatime) {
    player->pos.x +=
        player->dir.x * player->speed * deltatime;

    player->pos.y +=
        player->dir.y * player->speed * deltatime;
}

void key_handler(Player *player) {
    if (IsKeyDown(KEY_W)) player->dir.y = -1;
    else if (IsKeyDown(KEY_S)) player->dir.y = 1;
    else player->dir.y = 0;

    if (IsKeyDown(KEY_A)) player->dir.x = -1;
    else if (IsKeyDown(KEY_D)) player->dir.x = 1;
    else player->dir.x = 0;

    if (IsKeyDown(KEY_P)) {
        switch_light(player->lantern);
    }
}

void update_player(
    Player *player, const float deltatime
) {
    key_handler(player);
    move(player, deltatime);
}

void draw_player(Player *player) {
    static bool is_left = false;
    if (player->dir.y != 0 || player->dir.x != 0) {
    is_left = player->dir.x < 0;
        play_animation(
            player->texture,
            player->pos,
            true,
            is_left,
            4,
            2
        );
    } else {
        DrawTextureRec(
            player->texture,
            (Rectangle) {
                is_left * (player->texture.width / 4.0f),
                is_left * (player->texture.height / 2.0f),
                player->texture.width/4.0f,
                player->texture.height/2.0f},
            player->pos,
            WHITE
        );
    }

    draw_lantern(player->lantern);
}

void destroy_player(Player *player) {
    destroy_lantern(player->lantern);
    UnloadTexture(player->texture);
    free(player);
}
