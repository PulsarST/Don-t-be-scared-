#include <raylib.h>

static struct {
    struct {
        Camera2D camera;
    } Entities;
} Game;


static inline void init_game(
    float width, float height, const char *title
) {
    InitWindow(width, height, title);
    Game.Entities.camera = (Camera2D) { 0 };
    Game.Entities.camera.target = (Vector2) {
        .x = width / 2, .y = height / 2
    };
    Game.Entities.camera.offset = (Vector2) {
        width/2, height / 2
    };
    Game.Entities.camera.rotation = 0.0f;
    Game.Entities.camera.zoom = 1.0f;
}

static inline void draw() {
    BeginDrawing();
    ClearBackground(SKYBLUE);
    EndDrawing();
}

static inline void update() {

}

static void run_game() {
    while (!WindowShouldClose()) {
        draw();
        update();
    }
}

static inline void close_game() {
    CloseWindow();
}

int main() {
    init_game(1270, 720, "game");
    run_game();
    close_game();
}
