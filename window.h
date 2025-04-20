#ifndef __WINDOW_H__
#define __WINDOW_H__

#define INCLUDE_VULKAN_HEADER
#include <GLFW/glfw3.h>

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600

int init_window(int argc, char **argv);

GLFWwindow *get_window();

void destroy_window();

#endif
