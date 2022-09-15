#ifndef GAME_CODE_LOGIC_H_
#define GAME_CODE_LOGIC_H_

int check_life(int **matrix, int n, int m, int row, int column);
int allocate(int ***matrix, int n, int m);
int countAlive(int **matrix, int n, int m);
int update(int ***matrix, int n, int m);


#endif  // GAME_CODE_LOGIC_H_