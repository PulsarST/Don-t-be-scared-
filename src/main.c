#include <raylib.h>

#include "player.h"
#include "enemy.h"
#include "AABB.h"
#include "level.h"
#include "object.h"
#include "LOG.h"

static struct {
    float deltatime;
    Levels levels;
    struct {
        Camera2D camera;
        Player *player;
        Enemy *claws;
        Object generator;

    } Entities;
} Game;


static inline void init_game(
    float width, float height, const char *title
) {
    InitWindow(width, height, title);
    SetTargetFPS(60);
    SetConfigFlags(FLAG_VSYNC_HINT);
    ChangeDirectory(GetApplicationDirectory());

    Game.deltatime = 0.0f;
    Game.levels = create_level(
        "..\\res\\level.png",
        0.0f,
        0.0f);

    Game.Entities.player = create_player(
        width / 2 + 24,
        height / 2 + 24,
        500,
        "..\\res\\Player.png"
    );

    Game.Entities.claws = create_enemy(
        1200,
        650,
        200,
        "..\\res\\Claws.png");

    Game.Entities.camera = (Camera2D) { 0 };
    Game.Entities.camera.offset = (Vector2) {
        width/2, height / 2
    };
    Game.Entities.camera.rotation = 0.0f;
    Game.Entities.camera.zoom = 1.0f;

    Game.Entities.generator = create_object(
        200,
        1080,
        "..\\res\\generator.png",
        Static);
}

static inline void colliding() {
    if (collide_aabb(
        Game.Entities.player->collider,
        Game.Entities.claws->collider)
    ) {
        DrawText(
            "Claws collide with Player !",
            GetScreenWidth() / 2 - 20,
            GetScreenHeight() / 2 - 20,
            20,
            RAYWHITE);
    }
}

static inline void draw() {
    BeginDrawing();
        BeginMode2D(Game.Entities.camera);

        ClearBackground(BLACK);
        draw_level(Game.levels);
        draw_player(Game.Entities.player);
        draw_enemy(Game.Entities.claws);
        draw_object(Game.Entities.generator);
        
    EndMode2D();
    colliding();
    DrawFPS(50, 50);
    EndDrawing();
}

static inline void key_handler() {
    if (IsKeyDown(KEY_W))
        Game.Entities.player->dir.y = -1;
    else if (IsKeyDown(KEY_S))
        Game.Entities.player->dir.y = 1;
    else Game.Entities.player->dir.y = 0;

    if (IsKeyDown(KEY_A))
        Game.Entities.player->dir.x = -1;
    else if (IsKeyDown(KEY_D))
        Game.Entities.player->dir.x = 1;
    else Game.Entities.player->dir.x = 0;
}

static inline void update_camera_pos() {
    Game.Entities.camera.target.x = 
        Game.Entities.player->pos.x
        + Game.Entities.player->sprite->rect.width / 2;
    
    Game.Entities.camera.target.y = 
        Game.Entities.player->pos.y
        + Game.Entities.player->sprite->rect.height / 2;
}

static inline void update() {
    Game.deltatime = GetFrameTime();
    update_player(
        Game.Entities.player,
        Game.deltatime
    );
    move_enemy(
        Game.Entities.claws,
        Game.deltatime);
    follow_to(
        Game.Entities.claws,
        Game.Entities.player->pos);
    update_camera_pos();
    key_handler();
}

static void run_game() {
    while (!WindowShouldClose()) {
        draw();
        update();
    }
}

static inline void close_game() {
    destroy_player(Game.Entities.player);
    destroy_enemy(Game.Entities.claws);
    destroy_level(Game.levels);
    destroy_object(Game.Entities.generator);
    CloseWindow();
    INFO("game is succesfuly closed !");
}

int main() {
    init_game(1270, 720, "game");
    run_game();
    close_game();
}
