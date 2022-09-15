#ifndef GAME_CODE_CONTROL_H_
#define GAME_CODE_CONTROL_H_
 
void gameControl(char command, int *isManual, int *isPause, int *isExit, int *isCursor,
                 int *speedGame, int *k_x, int *k_y, int **field);

void pauseControl(int *isPause);
void cursorControl(char command, int *isCursor, int *k_x, int *k_y,
                   int **field);
void changeSpeedGame(char speedMode, int *speedGame);
int changeSpeedGameScanf();

void inputControl(int *isMatrix);

void zeroMatrix(int **a, int n, int m);
char toUpperCase(char letter);

#endif  // GAME_CODE_CONTROL_H_