#include <stdlib.h>
#include <ncurses.h>

#include "logic.h"
#include "tools.h"
#include "constants.h"
#include "control.h"


int checkLife(int **matrix, int n, int m, int row, int column) {
  int **neighbors;
  allocate(&neighbors, 8, 2);
  int counter = -1;
  int isSuccess = 0;
  for (int i = row - 1; i <= row + 1; i++) {
    for (int j = column - 1; j <= column + 1; j++) {
      if (i != row || j != column) {
        counter++;
        neighbors[counter][0] = i;
        neighbors[counter][1] = j;
      }
    }
  }
  for (int i = 0; i < 8; i++) {
    if (neighbors[i][0] < 0)
      neighbors[i][0] += n;
    if (neighbors[i][0] >= n)
      neighbors[i][0] -= n;
    if (neighbors[i][1] >= m)
      neighbors[i][1] -= m;
    if (neighbors[i][1] < 0)
      neighbors[i][1] += m;
  }
  counter = 0;
  for (int i = 0; i < 8; i++)
    counter += matrix[neighbors[i][0]][neighbors[i][1]];
  if (matrix[row][column] && (counter == 2 || counter == 3)) {
    isSuccess = 1;
  }
  if (!(matrix[row][column]) && counter == 3) {
    isSuccess = 1;
  }
  free(neighbors);
  return isSuccess;
}

int update(int ***matrix, int n, int m) {
  int **matrix_new;
  allocate(&matrix_new, n, m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      matrix_new[i][j] = checkLife(*matrix, n, m, i, j);
  int changes_check = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (matrix_new[i][j] != (*matrix)[i][j])
        changes_check = 0;
  free(*matrix);
  *matrix = matrix_new;
  return !changes_check;
}

int countAlive(int **matrix, int n, int m) {
  int result = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      result += matrix[i][j];
  return result;
}

void checkDeath(int **field, struct Flags *flags) {
    if (!countAlive(field, HEIGHT, WIDTH) && !flags->isInput)
        flags->isDeath = true;
}

void checkMovement(int ***field, struct Flags *flags) {
    if (!flags->isPause) {
        flags->isMovement = update(field, HEIGHT, WIDTH);
    }
}

void createField(int ***field) {
    allocate(field, HEIGHT, WIDTH);
}

void start() {
    initscr();
    noecho();
    nodelay(stdscr, true);
}

void end() {
    endwin();
}
