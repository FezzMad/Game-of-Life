#include <stdio.h>
#include <ncurses.h>

#include "control.h"
#include "constants.h"
#include "draw.h"


char toUpperCase(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        letter -= 32;
    }
    return letter;
}

void zeroMatrix(int **a, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = 0;
    }
  }
}

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

void gameControl(char command, int *isManual, int *isPause, int *isExit, int *isCursor,
                 int *SPEED_GAME, int *k_x, int *k_y, int **field) {
  switch (command) {
    case PAUSE: {
      switchControl(isPause);
      break;
    }
    case EXIT:
      *isExit = 1;
      break;
    case MANUAL: {
      switchControl(isManual);
    }
  }
  if (command >= '0' && command <= '9') {
    changeSpeedGame(command, SPEED_GAME);
  }
  cursorControl(command, isCursor, k_x, k_y, field);
}

void cursorControl(char command, int *isCursor, int *k_x, int *k_y,
                   int **field) {
  switch (command) {
  case CURSOR_SWITCH: {
    if (*isCursor == 0) {
      *isCursor = 1;
      *k_x = WIDTH / 2;
      *k_y = HEIGHT / 2;
    } else if (*isCursor == 1) {
      *isCursor = 0;
      *k_x = -1;
      *k_y = -1;
    }
    break;
  }
  case CURSOR_UP: {
    if (*isCursor)
      if (*k_y > 0)
        (*k_y)--;
    break;
  }
  case CURSOR_DOWN: {
    if (*isCursor)
      if (*k_y < HEIGHT - 1)
        (*k_y)++;
    break;
  }
  case CURSOR_LEFT: {
    if (*isCursor)
      if (*k_x > 0)
        (*k_x)--;
    break;
  }
  case CURSOR_RIGHT: {
    if (*isCursor)
      if (*k_x < WIDTH - 1)
        (*k_x)++;
    break;
  }
  case ENTER_LIFE: {
    if (*isCursor) {
      field[*k_y][*k_x] = 1;
    }
    break;
  }
  }
}

void changeSpeedGame(char speedMode, int *speedGame) {
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
    *speedGame = 100000;
  }
}

int changeSpeedGameScanf() {
  int speedMode;
  int speedGame;
  scanf("%d", &speedMode);
  changeSpeedGame(speedMode + '0', &speedGame);
  return speedGame;
}


