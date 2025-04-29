#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "vulkan_local.h"
#include <GLFW/glfw3.h>

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600

extern GLFWwindow *g_window;
extern VkSurfaceKHR g_surfase;

GLFWwindow *init_window(int argc, char **argv);

VkSurfaceKHR create_surfase();

#endif
