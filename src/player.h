#include <stdlib.h>
#include <stdbool.h>
#include <raylib.h>
#include <raymath.h>

#include "LOG.h"
#include "AABB.h"
#include "animator.h"
#include "utils\Colors.h"

typedef struct {
    Vector2 pos;
    Vector2 dir;
    float speed;
    Animation_sprite sprite;
    AABB collider;
} Player;

Player *create_player(
    float x,float y, float speed, const char* filename
);

static void move(Player *player, const float deltatime);
void update_player(Player *player, const float deltatime);
void draw_player(Player *player);
void destroy_player(Player *player);
