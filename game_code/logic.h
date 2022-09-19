#ifndef GAME_CODE_LOGIC_H_
#define GAME_CODE_LOGIC_H_

#include "control.h"

void createField(int ***field);
void checkDeath(int **field, struct Flags *flags);
void checkMovement(int ***field, struct Flags *flags);
void start();
void end();

#endif  // GAME_CODE_LOGIC_H_