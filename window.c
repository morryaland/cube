#include "window.h"
#include <stdio.h>
#include <getopt.h>
#include <string.h>

GLFWwindow *window;

int init_window(int argc, char **argv)
{
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
        fprintf(stderr, "%s %d: ERROR: symbol not found\n", __FILE__, __LINE__);
        return -1;
    }
  }
  glfwWindowHint(GLFW_NO_API, GL_TRUE);
  glfwWindowHint(GLFW_FLOATING, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, resize);
  window = glfwCreateWindow(width, height, title, NULL, NULL);
  if (!window) {
    fprintf(stderr, "%s %d: ERROR: window is not created\n", __FILE__, __LINE__);
    return -1;
  } 
  return 0;
}

GLFWwindow *get_window()
{
  return window;
}

void destroy_window()
{
  glfwDestroyWindow(window);
}
