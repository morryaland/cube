cube: cube.c main.c window.c vulkan.c
	gcc -o $@ $^ -O2 -g3 -lvulkan -lglfw
