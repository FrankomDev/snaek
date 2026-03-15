#include "state.h"

int score = 0;

state game_state = GAME;

state get_state() { return game_state; }

void end_game() { game_state = END; }
