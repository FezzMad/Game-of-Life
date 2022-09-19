#ifndef GAME_CODE_DRAW_H_
#define GAME_CODE_DRAW_H_

#include "control.h"

void drawField(int (*print)(const char *format, ...), int **A, int N, int M, struct Cursor cursor);

void drawOutOfField(int (*print)(const char *format, ...));
void drawSelectingInput(int (*print)(const char *format, ...));
void drawSelectingDrawing(int (*print)(const char *format, ...));

void drawHint(int (*print)(const char *format, ...));
void drawInputHelp(int (*print)(const char *format, ...));
void drawGameHelp(int (*print)(const char *format, ...));

void drawGreeting(int (*print)(const char *format, ...));
void drawDeath(int (*print)(const char *format, ...));
void drawGameOver(int (*print)(const char *format, ...));
void drawInfinity(int (*print)(const char *format, ...));

#endif  // GAME_CODE_DRAW_H_
