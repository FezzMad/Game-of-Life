#include <stdio.h>
#include <stdlib.h>

#include "tools.h"


char toUpperCase(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        letter -= 32;
    }
    return letter;
}

void zeroMatrix(int **matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrix[i][j] = 0;
    }
  }
}

void clean_stdin() {
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}

int isIntNumber(char ch) {
  if (ch >= '0' && ch <= '9')
    return 1;
  else
    return 0;
}

int charToInt(char ch) {
    return ch - 48;
}

void stringToMatrix(char *str, int **matrix) {
  int i = 0;
  int j = 0;
  int k = 0;
  while(str[i] != '\0') {
    if (isIntNumber(str[i])) {
      matrix[j][k] = charToInt(str[i]);
      k++;
    } else if (str[i] == '\n') {
        j++;
        k = 0;
    }
    i++;
  }
}

int allocate(int ***matrix, int n, int m) {
  int isSuccess = 0;
  *matrix = (int **)malloc(n * m * sizeof(int) + n * sizeof(int *));
  int *ptr = (int *)(*matrix + n);
  for (int i = 0; i < n; i++)
    (*matrix)[i] = ptr + m * i;
  return isSuccess;
}