#include "window.h"
#include <stdio.h>
#include <getopt.h>
#include <string.h>

GLFWwindow *g_window;
VkSurfaceKHR g_surfase;

GLFWwindow *init_window(int argc, char **argv)
{
  GLFWwindow *win;
  int width = DEFAULT_WIDTH;
  int height = DEFAULT_HEIGHT;
  char title[255] = "cube";
  int resize = 0;
  char c;
  while ((c = getopt(argc, argv, "w:h:t:r")) > 0) {
    switch (c) {
      case 'w':
        sscanf(optarg, "%d", &width);
        break;
      case 'h':
        sscanf(optarg, "%d", &height);
        break;
      case 't':
        strcpy(title, optarg);
        break;
      case 'r':
        resize = 1;
        break;
      default:
        fprintf(stderr, "ERR: symbol not found\n");
        return NULL;
    }
  }
  glfwWindowHint(GLFW_NO_API, GL_TRUE);
  glfwWindowHint(GLFW_FLOATING, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, resize);
  win = glfwCreateWindow(width, height, title, NULL, NULL);
  if (!win) {
    fprintf(stderr, "ERR: window is not created\n");
    return NULL;
  } 
  return win;
}

VkSurfaceKHR create_surfase()
{
  VkSurfaceKHR surfase;
  if (glfwCreateWindowSurface(g_vkInstance, g_window, NULL, &surfase) != VK_SUCCESS) {
    fprintf(stderr, "ERR: surface is not created\n");
    return NULL;
  }
  return surfase;
}
