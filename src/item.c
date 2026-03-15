#include "item.h"
#include "snake.h"
#include "state.h"
#include <raylib.h>
#include <raymath.h>
#include <stdbool.h>

Vector2 position;

bool is_snake_on_tile(Vector2 pos) {
  bool is = false;
  for (int i = 0; i < snake_size; i++) {
    if (Vector2Equals(snake[i], (Vector2){pos.x * SCALE, pos.y * SCALE})) {
      is = true;
      break;
    }
  }
  return is;
}

void item_spawn() {
  Vector2 new_pos = {GetRandomValue(0, 19), GetRandomValue(0, 19)};
  while (is_snake_on_tile(new_pos)) {
    new_pos = (Vector2){GetRandomValue(0, 19), GetRandomValue(0, 19)};
  }
  position = new_pos;
}

void item_draw() {
  DrawRectangle(position.x * SCALE, position.y * SCALE, SCALE, SCALE, RED);
}

void item_detect_collision() {
  if (Vector2Equals(snake[0],
                    (Vector2){position.x * SCALE, position.y * SCALE})) {
    snake_grow();
    item_spawn();
    score++;
  }
}
