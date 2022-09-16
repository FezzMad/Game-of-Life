#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "tools.h"
#include "constants.h"
#include "draw.h"
#include "files.h"
#include "tools.h"


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

void inputCoordinatesFromHuman(int **a, int n, int m) {
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
}