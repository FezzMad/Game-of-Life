#include <stdio.h>
#include <ncurses.h>

#include "control.h"
#include "constants.h"
#include "tools.h"


void inputControl(int *isMatrix) {
char command = toUpperCase(getchar());
  switch(command) {
      case 'Y': *isMatrix = 1; break;
      case 'N': *isMatrix = 0;
  }
  
}

void switchControl(int *flag) {
  if (*flag == 0) {
        *flag = 1;
  } else if (*flag == 1) {
        *flag = 0;
  }
}

void coordinatesCursorControl(int isCursor, int *k_x, int *k_y) {
  if (isCursor == 1) {
      *k_x = WIDTH / 2;
      *k_y = HEIGHT / 2;
    } else if (isCursor == 0) {
      *k_x = -1;
      *k_y = -1;
    }
}

void cursorUpControl(int isCursor, int *k_y) {
  if (isCursor)
      if (*k_y > 0)
        (*k_y)--;
}

void cursorDownControl(int isCursor, int *k_y) {
   if (isCursor)
      if (*k_y < HEIGHT - 1)
        (*k_y)++;
}

void cursorLeftControl(int isCursor, int *k_x) {
   if (isCursor)
      if (*k_x > 0)
        (*k_x)--;
}

void cursorRightControl(int isCursor, int *k_x) {
   if (isCursor)
      if (*k_x < WIDTH - 1)
        (*k_x)++;
}

void enterLifeControl(int isCursor, int **field, int k_x, int k_y) {
 if (isCursor) {
      field[k_y][k_x] = 1;
    }
}

void cursorControl(char command, int *isCursor, int *k_x, int *k_y,
                   int **field) {
  switch (command) {
  case CURSOR_SWITCH: {
    switchControl(isCursor);
    coordinatesCursorControl(*isCursor, k_x, k_y);
    break;
  }
  case CURSOR_UP: {
    cursorUpControl(*isCursor, k_y);
    break;
  }
  case CURSOR_DOWN: {
    cursorDownControl(*isCursor, k_y);
    break;
  }
  case CURSOR_LEFT: {
    cursorLeftControl(*isCursor, k_x);
    break;
  }
  case CURSOR_RIGHT: {
    cursorRightControl(*isCursor, k_x);
    break;
  }
  case ENTER_LIFE: {
    enterLifeControl(*isCursor, field, *k_x, *k_y);
    break;
  }
  }
}

void speedGameControl(char speedMode, int *speedGame) {
  switch (speedMode) {
  case '1':
    *speedGame = 1600000;
    break;
  case '2':
    *speedGame = 800000;
    break;
  case '3':
    *speedGame = 400000;
    break;
  case '4':
    *speedGame = 200000;
    break;
  case '5':
    *speedGame = 100000;
    break;
  case '6':
    *speedGame = 50000;
    break;
  case '7':
    *speedGame = 25000;
    break;
  case '8':
    *speedGame = 6250;
    break;
  case '9':
    *speedGame = 3125;
    break;
  case '0':
    *speedGame = 1561;
    break;
  default:
    *speedGame = DEFAULT_SPEED;
  }
}

void gameControl(char command, int *isHelp, int *isPause, int *isExit, int *isCursor,
                 int *SPEED_GAME, int *k_x, int *k_y, int **field) {
  switch (command) {
    case PAUSE: {
      switchControl(isPause);
      break;
    }
    case EXIT:
      *isExit = 1;
      break;
    case HELP: {
      switchControl(isHelp);
    }
  }
  if (command >= '0' && command <= '9') {
    speedGameControl(command, SPEED_GAME);
  }
  cursorControl(command, isCursor, k_x, k_y, field);
}


