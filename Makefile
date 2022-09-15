game_of_life: game_code/*.c
	gcc -o Game_of_Life game_code/*.c -lncurses

clean:
	rm -rf Game_of_Life
