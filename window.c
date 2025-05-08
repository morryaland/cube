#include "window.h"
#include <stdio.h>
#include <getopt.h>
#include <string.h>

GLFWwindow *init_window(int width, int height, int resize, char title[255])
{
  GLFWwindow *win;
  if (!width)
    width = DEFAULT_WIDTH;
  if (!height)
    height = DEFAULT_HEIGHT;
  if (!*title)
    title = "cube";
  glfwWindowHint(GLFW_FLOATING, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, resize);
  win = glfwCreateWindow(width, height, title, NULL, NULL);
  if (!win) {
    fprintf(stderr, "ERR: window is not created\n");
    return NULL;
  } 
  return win;
}
