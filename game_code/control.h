#ifndef GAME_CODE_CONTROL_H_
#define GAME_CODE_CONTROL_H_
 
void gameControl(char command, int *isManual, int *isPause, int *isExit, int *isCursor,
                 int *speedGame, int *k_x, int *k_y, int **field);
void inputControl(int *isMatrix);

#endif  // GAME_CODE_CONTROL_H_