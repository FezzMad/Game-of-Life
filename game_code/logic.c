#include <stdlib.h>
#include "logic.h"

// проверяет, будет ли жить клетка в следующий ход
int check_life(int **matrix, int n, int m, int row, int column) {
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

// выделение памяти для матрицы
int allocate(int ***matrix, int n, int m) {
  int isSuccess = 0;
  *matrix = (int **)malloc(n * m * sizeof(int) + n * sizeof(int *));
  int *ptr = (int *)(*matrix + n);
  for (int i = 0; i < n; i++)
    (*matrix)[i] = ptr + m * i;
  return isSuccess;
}

// возвращает матрицу 'нового' поколения клеток
int update(int ***matrix, int n, int m) {
  int **matrix_new;
  allocate(&matrix_new, n, m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      matrix_new[i][j] = check_life(*matrix, n, m, i, j);
  int changes_check = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (matrix_new[i][j] != (*matrix)[i][j])
        changes_check = 0;
  free(*matrix);
  *matrix = matrix_new;
  return !changes_check;
}



// подсчёт живых клеток
int countAlive(int **matrix, int n, int m) {
  int result = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      result += matrix[i][j];
  return result;
}