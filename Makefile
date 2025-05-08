cube: cube.c main.c window.c ctl.c
	gcc -o $@ $^ -O2 -g3 -lGL -lcairo -lglfw
