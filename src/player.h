#include <stdlib.h>
#include <stdbool.h>
#include <raylib.h>

#include "AABB.h"
#include "animator.h"

typedef struct {
    Vector2 pos;
    Vector2 dir;
    float speed;
    Texture2D texture;
    AABB collider;
} Player;

Player *create_player(
    float x,float y, float speed, const char* filename
);

static void move(Player *player, float deltatime);
void update_player(Player *player, float deltatime);
void draw_player(Player *player);
void destroy_player(Player *player);
