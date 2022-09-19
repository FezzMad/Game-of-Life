#ifndef GAME_CODE_CONTROL_H_
#define GAME_CODE_CONTROL_H_

struct Flags {
    int isExit;
    int isDeath;
    int isPause;
    int isMovement;
    int isCursor;
    int isHelp;
    int isInput;
};

struct Cursor {
    int x;
    int y;
};


void gameControl(char command, struct Flags *flags, int *speedGame, struct Cursor *cursor, int **field);
void inputControl(int **field, struct  Flags *flags, struct  Cursor *cursor);
void defaultFlags(struct Flags *flags);
void defaultCoordinates(struct Cursor *cursor);
void pass();

#endif  // GAME_CODE_CONTROL_H_