#include "state.h"
#include "item.h"
#include "snake.h"

int score = 0;

state game_state = GAME;

state get_state() { return game_state; }

void end_game() { game_state = END; }

void restart_game() {
  snake_load();
  item_spawn();
  score = 0;
  game_state = GAME;
}
