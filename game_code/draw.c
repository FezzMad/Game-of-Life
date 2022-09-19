#include <stdio.h>

#include "draw.h"
#include "constants.h"
#include "control.h"


void drawField(int (*print)(const char *format, ...), int **A, int N, int M, struct Cursor cursor) {
    int k_x = cursor.x;
    int k_y = cursor.y;
    for (int x = 0; x <= WIDTH + 1; x++) {
        print("%c", SYMBOL_BORT);
        if (x == WIDTH + 1)
            print("\n");
    }
    for (int y = 0; y < N; y++) {
        print("%c", SYMBOL_BORT_SIDE);
        for (int x = 0; x < M; x++) {
            if (A[y][x] != 1 && x == k_x && y == k_y)
                print("%c", SYMBOL_K_DEATH);
            else if (A[y][x] == 1 && x == k_x && y == k_y)
                print("%c", SYMBOL_K_LIVE);
            else if (A[y][x] == 1)
                print("%c", SYMBOL_LIVE);
            else if (A[y][x] == 0)
                print("%c", SYMBOL_DEATH);
        }
        print("%c", SYMBOL_BORT_SIDE);
        if (y < M - 1)
            print("\n");
    }
    for (int x = 0; x <= WIDTH + 1; x++) {
        print("%c", SYMBOL_BORT);
        if (x == WIDTH + 1)
            print("\n");
    }
}

void drawOutOfField(int (*print)(const char *format, ...)) {
    printf("Out of field %dx%d\n", WIDTH, HEIGHT);
}

void drawSelectingInput(int (*print)(const char *format, ...)) {
    print("Do you want to upload ready-made coordinates?[Y/N]\n");
}

void drawSelectingDrawing(int (*print)(const char *format, ...)) {
    print("Enter the name of the prepared picture with the extension 'txt':\n");
}

void drawGameHelp(int (*print)(const char *format, ...)) {
    print("==================================================================================\n");
    print("                                                                                  \n");
    print(" To add a new cell to the field, activate the cursor using the 'K' key            \n");
    print(" and press 'ENTER'.                                                               \n");
    print("                                                                                  \n");
    print(" If you press 'K' key again, the cursor disappears from the screen.               \n");
    print("                                                                                  \n");
    print(" To move the cursor, use 'W', 'A', 'S', 'D' - up, left, down, right.              \n");
    print("                                                                                  \n");
    print(" To change the speed of the game, use the keys '0','1', ... ,'9'.                 \n");
    print("                                                                                  \n");
    print(" To pause the game, press the 'SPACE'                                             \n");
    print("                                                                                  \n");
    print(" To exit the game, press ESC.                                                     \n");
    print("                                                                                  \n");
    print("==================================================================================\n");

}

void drawInputHelp(int (*print)(const char *format, ...)) {
    print("==================================================================================\n");
    print("                                                                                  \n");
    print("                    Enter the coordinates to start the game.                      \n");
    print("                                                                                  \n");
    print("                                  For example:                                    \n");
    print("                                                                                  \n");
    print("                                     30 8                                         \n");
    print("                                     31 9                                         \n");
    print("                                     29 10                                        \n");
    print("                                     30 10                                        \n");
    print("                                     31 10.                                       \n");
    print("                                                                                  \n");
    print("==================================================================================\n");
}


void drawGreeting(int (*print)(const char *format, ...)) {
    print("==================================================================================\n");
    print("                                                                                  \n");
    print("                                                                                  \n");
    print("                         x  x                                                     \n");
    print("                             x      xx                                            \n");
    print("                         x   x     xxxx                                           \n");
    print("           x              xxxx     xx xx                                          \n");
    print("          xxx          x             xx                                           \n");
    print("         x x x      x  x      x x                    Welcome to the game          \n");
    print("        xxx xxx     x        x  xx                     <Game of life>!            \n");
    print("         x x x      x  x      x x                                                 \n");
    print("          xxx          x                                                          \n");
    print("           x              xxxx       xx                                           \n");
    print("                         x   x     xx xx                                          \n");
    print("                             x     xxxx                                           \n");
    print("                         x  x       xx                                            \n");
    print("                                                                                  \n");
    print("                                                                                  \n");
    print("==================================================================================\n");
}

void drawGameOver(int (*print)(const char *format, ...)) {
    print("==================================================================================\n");
    print("                                                                                  \n");
    print("     X X          X X                                                             \n");
    print("      XX           XX                                                             \n");
    print("      X            X                             Game was exit.                   \n");
    print("           X             X                                                        \n");
    print("            XX            XX                                                      \n");
    print("           XX            XX                                                       \n");
    print("                                                                                  \n");
    print("==================================================================================\n");
}

void drawDeath(int (*print)(const char *format, ...)) {
    print("==================================================================================\n");
    print("                                                                                  \n");
    print("             XXXXXXXXXX                                                           \n");
    print("          XXX          XXX                                                        \n");
    print("        XX                XX                                                      \n");
    print("       X    xxxx     xxxx   X                                                     \n");
    print("      X    x  X x   x  X x   X                 Death has come!                    \n");
    print("      X     xxxx     xxxx    X                                                    \n");
    print("       X         x  x       X                                                     \n");
    print("        XXX              XXX                                                      \n");
    print("           XX   X  X  X  XX                                                       \n");
    print("                X  X  X                                                           \n");
    print("                X  X  X                                                           \n");
    print("                                                                                  \n");
    print("==================================================================================\n");
}

void drawInfinity(int (*print)(const char *format, ...)) {
    print("==================================================================================\n");
    print("                                                                                  \n");
    print("       XXXXXXXX           XXXXXXXX                                                \n");
    print("     X         XX       XX         X                                              \n");
    print("    X             XX  XX            X      The cells have reached the limit!      \n");
    print("   X                XX               X                                            \n");
    print("    X             XX  XX            X                                             \n");
    print("     X          XX      XX         X                                              \n");
    print("      XXXXXXXXXX          XXXXXXXXX                                               \n");
    print("                                                                                  \n");
    print("==================================================================================\n");
}

void drawHint(int (*print)(const char *format, ...)) {
    print("                              Press 'H' for help.                                 \n");
}