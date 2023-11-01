#include <raylib.h>

#include "LOG.h"
#include "player.h"

static struct {
    float deltatime;
    struct {
        Camera2D camera;
        Player *player;
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

    Game.Entities.player = create_player(
        width / 2 + 24,
        height / 2 + 24,
        500,
        "..\\res\\Player.png"
    );

    Game.Entities.camera = (Camera2D) { 0 };
    Game.Entities.camera.offset = (Vector2) {
        width/2, height / 2
    };
    Game.Entities.camera.rotation = 0.0f;
    Game.Entities.camera.zoom = 1.0f;
}

static inline void draw() {
    BeginDrawing();
    BeginMode2D(Game.Entities.camera);

    ClearBackground(BLACK);
    DrawRectangle(50, 45, 100, 100, RED);
    draw_player(Game.Entities.player);
    
    EndMode2D();
    EndDrawing();
}

static inline void update() {
    Game.deltatime = GetFrameTime();
    update_player(
        Game.Entities.player, Game.deltatime
    );
    Game.Entities.camera.target.x = 
        Game.Entities.player->pos.x + 24;
    
    Game.Entities.camera.target.y = 
        Game.Entities.player->pos.y + 24;
    
}

static void run_game() {
    while (!WindowShouldClose()) {
        draw();
        update();
    }
}

static inline void close_game() {
    destroy_player(Game.Entities.player);
    CloseWindow();
    INFO("game is succesfuly closed !");
}

int main() {
    init_game(1270, 720, "game");
    run_game();
    close_game();
}
