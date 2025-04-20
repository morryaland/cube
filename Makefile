cube: cube.c main.c window.c vulkan.c vulkan_instance.c
	gcc -o $@ $^ -O2 -g3 -lvulkan -lglfw
