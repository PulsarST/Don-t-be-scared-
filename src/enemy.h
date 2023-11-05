#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <raymath.h>

#include "LOG.h"
#include "AABB.h"
#include "animator.h"

typedef struct {
    Vector2 pos;
    Vector2 dir;
    float speed;
    Animation_sprite *sprite;
    AABB collider;
    Circle_aabb affect_radius;
} Enemy;

Enemy *create_enemy(
    float x, float y, float speed, const char* filename);

void draw_enemy(Enemy *enemy);
void move_enemy(Enemy *enemy, const float deltatime);
void follow_to(Enemy *enemy, Vector2 follow_pos);
void destroy_enemy(Enemy *enemy);

