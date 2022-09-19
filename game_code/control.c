#include <ncurses.h>
#include <stdio.h>

#include "control.h"
#include "input.h"
#include "constants.h"
#include "tools.h"


void defaultFlags(struct Flags *flags) {
    flags->isExit = false;
    flags->isDeath = false;
    flags->isPause = false;
    flags->isCursor = false;
    flags->isHelp = false;
    flags->isMovement = true;
    flags->isInput = false;
}

void defaultCoordinates(struct Cursor *cursor) {
    cursor->x = -1;
    cursor->y = -1;
}

void pass() {}

void switchControl(int *flag) {
    if (!*flag) {
        *flag = true;
    } else if (*flag) {
        *flag = false;
    }
}

void coordinatesCursor(int isCursor, struct Cursor *cursor) {
    if (isCursor) {
        cursor->x = WIDTH / 2;
        cursor->y = HEIGHT / 2;
    } else if (!isCursor) {
        cursor->x = -1;
        cursor->y = -1;
    }
}

void inputControl(int **field, struct Flags *flags, struct  Cursor *cursor) {
    char command = toUpperCase(getchar());
    switch (command) {
        case 'Y':
            coordinatesFromFile(field);
            break;
        case 'N':
            flags->isPause = true;
            flags->isCursor = true;
            flags->isInput = true;
            coordinatesCursor(flags->isCursor, cursor);
            break;
        default:
            pass();
    }
}

void cursorUp(int isCursor, int *y) {
    if (isCursor)
        if (*y > 0)
            (*y)--;
}

void cursorDown(int isCursor, int *y) {
    if (isCursor)
        if (*y < HEIGHT - 1)
            (*y)++;
}

void cursorLeft(int isCursor, int *x) {
    if (isCursor)
        if (*x > 0)
            (*x)--;
}

void cursorRight(int isCursor, int *x) {
    if (isCursor)
        if (*x < WIDTH - 1)
            (*x)++;
}

void enterLife(int isCursor, int **field, struct Cursor *cursor) {
    if (isCursor) {
        field[cursor->y][cursor->x] = 1;
    }
}

void cursorControl(char command, int *isCursor, struct Cursor *cursor, int **field) {
    switch (command) {
        case CURSOR_SWITCH: {
            switchControl(isCursor);
            coordinatesCursor(*isCursor, cursor);
            break;
        }
        case CURSOR_UP: {
            cursorUp(*isCursor, &cursor->y);
            break;
        }
        case CURSOR_DOWN: {
            cursorDown(*isCursor, &cursor->y);
            break;
        }
        case CURSOR_LEFT: {
            cursorLeft(*isCursor, &cursor->x);
            break;
        }
        case CURSOR_RIGHT: {
            cursorRight(*isCursor, &cursor->x);
            break;
        }
        case ENTER_LIFE: {
            enterLife(*isCursor, field, cursor);
            break;
        }
        default:
            pass();
    }
}

void speedGameControl(char speedMode, int *speedGame) {
    switch (speedMode) {
        case '1':
            *speedGame = 1600000;
            break;
        case '2':
            *speedGame = 800000;
            break;
        case '3':
            *speedGame = 400000;
            break;
        case '4':
            *speedGame = 200000;
            break;
        case '5':
            *speedGame = 100000;
            break;
        case '6':
            *speedGame = 50000;
            break;
        case '7':
            *speedGame = 25000;
            break;
        case '8':
            *speedGame = 6250;
            break;
        case '9':
            *speedGame = 3125;
            break;
        case '0':
            *speedGame = 2000;
            break;
        default:
            pass();
    }
}

void offInput(int *isInput) {
    *isInput = false;
}

void stateGameControl(char command, struct Flags *flags) {
    switch (command) {
        case PAUSE: {
            switchControl(&flags->isPause);
            offInput(&flags->isInput);
            break;
        }
        case EXIT:
            flags->isExit = true;
            break;
        case HELP: {
            switchControl(&flags->isHelp);
        }
        default:
            pass();
    }
}

void gameControl(char command, struct Flags *flags, int *speedGame, struct Cursor *cursor, int **field) {
    stateGameControl(command, flags);
    speedGameControl(command, speedGame);
    cursorControl(command, &flags->isCursor, cursor, field);
}




