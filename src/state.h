#ifndef STATE_H
#define STATE_H

typedef enum { GAME, END } state;

void end_game();
state get_state();

extern int score;

#endif // STATE_H
