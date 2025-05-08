#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <GLFW/glfw3.h>

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600

GLFWwindow *init_window(int width, int height, int resize, char title[255]);

#endif
