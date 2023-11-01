#include <stdlib.h>
#include <stdbool.h>
#include <raylib.h>

#include "LOG.h"
#include "AABB.h"
#include "animator.h"
#include "lantern_gun.h"

typedef struct {
    Vector2 pos;
    Vector2 dir;
    float speed;
    Texture2D texture;
    AABB collider;

    Lantern_gun *lantern;
} Player;

Player *create_player(
    float x,float y, float speed, const char* filename
);

static void move(Player *player, const float deltatime);
static void key_handler(Player *player);
void update_player(Player *player, const float deltatime);
void draw_player(Player *player);
void destroy_player(Player *player);
