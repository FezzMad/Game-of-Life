#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "input.h"
#include "control.h"
#include "constants.h"
#include "draw.h"
#include "files.h"


#include "control.h"

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

char *inputString() {
    char *str = malloc(sizeof(char));
    clean_stdin();
    int i = 0;
    char element;
    while (element != '\n') {
        scanf("%c", &element);
        str[i] = element;
        i++;
    }
    str[i - 1] = '\0';
    return str;
}

void inputCoordinatesFromFile(int **a, int n, int m) {
  char *file = inputString();
  char *drawing = fileToStr(file);
  free(file);
  stringToMatrix(drawing, a);
  free(drawing);
}

int inputCoordinatesFromHuman(int **a, int n, int m) {
  int isSuccess = 1;
  int x = 0;
  int y = 0;
  int end = 0;
  char endOfCoordinates;
  zeroMatrix(a, n, m);
  while (!end) {
    fflush(stdin);
    scanf("%d%d%c", &x, &y, &endOfCoordinates);
    isSuccess = 1;
    x--;
    y--;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
      drawOutOfField(printf);
      isSuccess = 0;
    }

    if (isSuccess)
      a[y][x] = 1;
    if (endOfCoordinates == '.') {
      end = 1;
    }
  }
  return isSuccess;
}