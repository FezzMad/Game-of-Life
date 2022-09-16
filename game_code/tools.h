#ifndef GAME_TOOLS_H_
#define GAME_TOOLSL_H_

void stringToMatrix(char *str, int **matrix);
void zeroMatrix(int **matrix, int n, int m);
void clean_stdin();

int allocate(int ***matrix, int n, int m);
int isIntNumber(char ch);
int charToInt(char ch);

char toUpperCase(char letter);

#endif  // GAME_TOOLS_H_