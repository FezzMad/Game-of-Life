#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "tools.h"
#include "files.h"
#include "draw.h"
#include "constants.h"


char *inputString() {
    char *str = malloc(sizeof(char));
    clean_stdin();
    int i = 0;
    char element = ' ';
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

void coordinatesFromFile(int **field) {
    drawSelectingDrawing(printf);
    inputCoordinatesFromFile(field, HEIGHT, WIDTH);
}
