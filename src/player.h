#include <stdlib.h>
#include <stdbool.h>
#include <raylib.h>
#include <raymath.h>

#include "LOG.h"
#include "AABB.h"
#include "animator.h"
#include "item.h"
#include "utils\Colors.h"

#define MAX_ITEMS 3

typedef struct {
    Vector2 pos;
    Vector2 dir;
    float speed;
    Animation_sprite *sprite;
    AABB collider;
    Circle_aabb affect_radius;

    Item *items[MAX_ITEMS];
} Player;

Player *create_player(
    float x,float y, float speed, const char* filename
);

static void move_player(Player *player, const float deltatime);
void update_player(Player *player, const float deltatime);
void draw_player(Player *player);
void add_item(Player *player, Item *item);
void destroy_player(Player *player);
