#include "enemy.h"
#include <stdlib.h>

Enemy *create_enemy(
    float x, float y, float speed, const char* filename
) {
    Enemy *enemy = malloc(sizeof(Enemy));
    ASSERT(enemy != NULL, "enemy doesn't loaded");
    enemy->pos = (Vector2) {x, y};
    Image img = LoadImage(filename);
    ImageResize(
        &img,
        img.width * 3,
        img.height * 3);
    enemy->sprite = create_sprite(
        LoadTextureFromImage(img),
        &enemy->pos,
        4,
        8, 7.0f);
    enemy->dir = Vector2Zero();
    enemy->speed = speed;
    enemy->collider = (AABB) { 0 };
    enemy->affect_radius = (Circle_aabb) { 0 };

    return enemy;
}

void draw_enemy(Enemy *enemy) {
    int anim_row = 0;
    static int tmp_anim_row = 1;
    if (enemy->dir.x > 0) {
        anim_row = 0;
        tmp_anim_row = 1;
    } else if (enemy->dir.x < 0) {
        anim_row = 2;
        tmp_anim_row = 3;
    } else if (enemy->dir.y > 0) {
        anim_row = 4;
        tmp_anim_row = 5;
    } else if (enemy->dir.y < 0) {
        anim_row = 6;
        tmp_anim_row = 7;
    } else anim_row = tmp_anim_row;
    play_animation_pro(
        enemy->sprite, anim_row);
    draw_circle_aabb(enemy->affect_radius);
}

void move_enemy(Enemy *enemy, const float deltatime) {
    Vector2 normalized_vector =
        Vector2Normalize(enemy->dir);
    enemy->pos.x +=
        normalized_vector.x * enemy->speed * deltatime;
    enemy->pos.y +=
        normalized_vector.y * enemy->speed * deltatime;

    update_aabb(
        &enemy->collider,
        enemy->pos.x,
        enemy->pos.y,
        (float) enemy->sprite->texture.width
        / enemy->sprite->collumns / 2,
        (float) enemy->sprite->texture.height
        / enemy->sprite->rows / 2);

    update_circle_aabb(
        &enemy->affect_radius,
        enemy->pos.x
        + (float) enemy->sprite->texture.width
        / enemy->sprite->collumns / 2,
        enemy->pos.y
        + (float) enemy->sprite->texture.height
        / enemy->sprite->rows / 2,
        350);
}

void follow_to(Enemy *enemy, Vector2 follow_pos) {
    if (follow_pos.x > enemy->pos.x) enemy->dir.x = 1;
    else if (follow_pos.x < enemy->pos.x)
        enemy->dir.x = -1;
    else enemy->dir.x = 0;

    if (follow_pos.y > enemy->pos.y) enemy->dir.y = 1;
    else if (follow_pos.y < enemy->pos.y)
        enemy->dir.y = -1;
    else enemy->dir.y = 0;
}

void destroy_enemy(Enemy *enemy) {
    destroy_sprite(enemy->sprite);
    free(enemy);    
}
