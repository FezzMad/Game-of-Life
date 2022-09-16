#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "constants.h"
#include "draw.h"
#include "control.h"
#include "input.h"
#include "logic.h"
#include "tools.h"


int main() {
  int SPEED_GAME = DEFAULT_SPEED;
  int k_x = -1;
  int k_y = -1;
  int isMatrix = 0;

  int **field = NULL;
  allocate(&field, HEIGHT, WIDTH);

  drawGreeting(printf);

  drawSelectingInput(printf);
  inputControl(&isMatrix);
  if (isMatrix) {    
    drawSelectingDrawing(printf);
    inputCoordinatesFromFile(field, HEIGHT, WIDTH);
  } else {
    drawInputHelp(printf);
    inputCoordinatesFromHuman(field, HEIGHT, WIDTH);
  }
  

  initscr();
  noecho();
  nodelay(stdscr, true);

  drawField(printw, field, HEIGHT, WIDTH, k_x, k_y);

  int isExit = 0;
  int isDeath = 0;
  int isPause = 0;
  int isMovement = 1;
  int isCursor = 0;
  int isHelp = 0;

  while (!isExit && !isDeath && isMovement) {
    usleep(SPEED_GAME);
    refresh();
    clear();

    if (!isPause) {
      isMovement = update(&field, HEIGHT, WIDTH);
    }

    if (!isHelp) {
      drawField(printw, field, HEIGHT, WIDTH, k_x, k_y);
      drawHint(printw);
    } else {
      isPause = 1;
      drawGameHelp(printw);
    }

    gameControl(toUpperCase(getch()), &isHelp, &isPause, &isExit, &isCursor, &SPEED_GAME, &k_x, &k_y,
                field);

    if (!countAlive(field, HEIGHT, WIDTH))
      isDeath = 1;
  }
  endwin();

  drawField(printf, field, HEIGHT, WIDTH, k_x, k_y);
  if (isExit) {
    drawGameOver(printf);
  } else if (isDeath) {
    drawDeath(printf);
  } else if (!isMovement) {
    drawInfinity(printf);
  }

  free(field);
  return 0;
}