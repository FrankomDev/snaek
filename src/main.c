#include "item.h"
#include "snake.h"
#include "state.h"
#include <raylib.h>
#include <stdio.h>
#include <string.h>

int main() {

  InitWindow(SCALE * TILES, SCALE * TILES, "Snake");
  SetTargetFPS(60);

  snake_load();
  item_spawn();

  while (!WindowShouldClose()) {

    if (get_state() == GAME) {
      snake_update();
      item_detect_collision();
    }

    BeginDrawing();
    ClearBackground(GRAY);

    switch (get_state()) {
    case GAME:
      item_draw();
      snake_draw();

      for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
          DrawRectangleLines(j * SCALE, i * SCALE, SCALE, SCALE, DARKGRAY);
        }
      }
      break;

    case END: {
      const char *text = "Game Over!";
      int font_size = 40;
      int width = MeasureText(text, font_size);
      DrawText(text, GetScreenWidth() / 2 - width / 2, 100, font_size, RED);
      char print_score[10] = "Score: ";
      char score_text[3];
      sprintf(score_text, "%d", score);
      strcat(print_score, score_text);
      width = MeasureText(print_score, font_size);
      DrawText(print_score, GetScreenWidth() / 2 - width / 2, 200, font_size,
               RED);
      break;
    }
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
