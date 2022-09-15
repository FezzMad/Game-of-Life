# Pong game
[Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) on C language for terminal Linux

## Libraries
- [`ncurses`](https://en.wikipedia.org/wiki/Ncurses) - for real-time mode 

Installing the ncurses library in Debian/Ubuntu Linux:
```
$ sudo apt install ncurses-bin
```
- [`unistd`](https://en.wikipedia.org/wiki/Unistd.h) - for the delay between cards in microseconds
- [`stdio`](https://www.tutorialspoint.com/c_standard_library/stdio_h.htm) - for other primitive actions (e. g. printf())

## Compilation
Go to the Pong-game folder and enter in the terminal:
```
$ make
```
Compiled by Pong_game. Run Pong_game in the terminal:
```
$ ./Game_of_Life
```