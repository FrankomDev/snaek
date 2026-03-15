#ifndef SNAKE_H
#define SNAKE_H

#include <raylib.h>

#define SCALE 30.0f
#define TILES 20

void snake_load();
void snake_update();
void snake_draw();
void snake_grow();

extern Vector2 snake[20 * 20];
extern int snake_size;

#endif // SNAKE_H
