#ifndef GAME_CODE_INPUT_H_
#define GAME_CODE_INPUT_H_

int inputCoordinatesFromHuman(int **a, int n, int m);
void inputCoordinatesFromFile(int **a, int n, int m);
void clean_stdin();
char *inputString();
void stringToMatrix(char *str, int **matrix);

#endif  // GAME_CODE_INPUT_H_