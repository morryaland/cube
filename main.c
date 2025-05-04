#include "window.h"
#include "ctl.h"
#include <stdio.h>
#include <assert.h>
#include <getopt.h>


int main(int argc, char **argv)
{
  GLFWwindow *window;
  glfwInit();
  ctl_t props = parse_args(argc, argv);
  window = init_window(props.width, props.height, props.flags & CTLRESIZE,
      props.title, props.flags & CTLZERO_MODE || props.flags & CTLVULKAN);

  for (;!glfwWindowShouldClose(window);) {
    glfwPollEvents();
  }
  return 0;
}
