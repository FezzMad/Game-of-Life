#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "constants.h"
#include "draw.h"
#include "control.h"
#include "logic.h"
#include "tools.h"


int main() {
    int SPEED_GAME = DEFAULT_SPEED;

    struct Cursor cursor;
    defaultCoordinates(&cursor);

    struct Flags flags;
    defaultFlags(&flags);

    int **field = NULL;
    createField(&field);

    drawGreeting(printf);
    drawSelectingInput(printf);
    inputControl(field, &flags, &cursor);

    start();
    while (!flags.isExit && !flags.isDeath && flags.isMovement) {
        usleep(SPEED_GAME);
        clear();
        checkMovement(&field, &flags);
        if (!flags.isHelp) {
            drawField(printw, field, HEIGHT, WIDTH, cursor);
        } else {
            flags.isPause = true;
            drawGameHelp(printw);
        }
        gameControl(toUpperCase(getch()), &flags, &SPEED_GAME, &cursor, field);
        checkDeath(field, &flags);
        refresh();
    }
    end();

    drawField(printf, field, HEIGHT, WIDTH, cursor);
    if (flags.isExit) {
        drawGameOver(printf);
    } else if (flags.isDeath) {
        drawDeath(printf);
    } else if (!flags.isMovement) {
        drawInfinity(printf);
    }

    free(field);
    return 0;
}