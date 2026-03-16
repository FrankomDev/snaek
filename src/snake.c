#include "snake.h"
#include "state.h"
#include <raylib.h>
#include <raymath.h>
#include <stdbool.h>

enum { UP, DOWN, RIGHT, LEFT } side;
int snake_size;
Vector2 snake[20 * 20];

void snake_load() {
  side = RIGHT;
  snake_size = 2;

  for (int i = 0; i < 2; i++) {
    snake[i] = (Vector2){5 * SCALE - i * SCALE, 5 * SCALE};
  }
}

void hit_wall() {
  if (snake[0].x < 0 || snake[0].x > SCALE * TILES - 1 || snake[0].y < 0 ||
      snake[0].y > SCALE * TILES - 1) {
    end_game();
  }
}
void hit_itself() {
  for (int i = 1; i < snake_size; i++) {
    if (Vector2Equals(snake[0], snake[i])) {
      end_game();
    }
  }
}

void snake_update() {

  static float move_timer = 0;
  static int input_frame = 0;
  move_timer += GetFrameTime();

  hit_wall();
  hit_itself();

  if (input_frame >= 1 && input_frame < 5)
    input_frame++;
  else if (input_frame == 5)
    input_frame = 0;

  if (input_frame == 0) {
    if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && side != DOWN) {
      side = UP;
      input_frame++;
    } else if ((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) && side != UP) {
      side = DOWN;
      input_frame++;
    } else if ((IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) &&
               side != LEFT) {
      side = RIGHT;
      input_frame++;
    } else if ((IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) &&
               side != RIGHT) {
      side = LEFT;
      input_frame++;
    }
  }

  if (move_timer >= 0.085f) {
    Vector2 new_snake[snake_size];
    for (int i = 0; i < snake_size; i++) {
      if (i == 0) {
        switch (side) {
        case UP:
          new_snake[0] = (Vector2){snake[0].x, snake[0].y - SCALE};
          break;
        case DOWN:
          new_snake[0] = (Vector2){snake[0].x, snake[0].y + SCALE};
          break;
        case RIGHT:
          new_snake[0] = (Vector2){snake[0].x + SCALE, snake[0].y};
          break;
        case LEFT:
          new_snake[0] = (Vector2){snake[0].x - SCALE, snake[0].y};
          break;
        default:
          break;
        }
      } else {
        new_snake[i] = snake[i - 1];
      }
    }
    for (int i = 0; i < snake_size; i++) {
      snake[i] = new_snake[i];
    }

    move_timer = 0;
  }
  hit_wall();
  hit_itself();
}

void snake_draw() {
  for (int i = 0; i < snake_size; i++) {
    Color color;
    if (i == 0)
      color = DARKGREEN;
    else
      color = GREEN;

    DrawRectangleV(snake[i], (Vector2){SCALE, SCALE}, color);
  }
}

void snake_grow() {
  snake[snake_size] = (Vector2){-100, -100};
  snake_size++;
}
