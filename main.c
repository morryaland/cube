#include "window.h"
#include "vulkan.h"
#include <stdio.h>
#include <assert.h>
#include <getopt.h>


int main(int argc, char **argv)
{
  /* help */
  struct option opt[] = {{"help", 0, 0, 'h'}, {}};
  if (getopt_long(argc, argv, "h", opt, NULL) == 'h') {
    puts(
"  -h, --help\tthis help\n"
"  -r\t\tresize mode\n"
"  -w\t\twidth\n"
"  -h\t\theight\n"
"  -t\t\ttitle\n"
    );
    return 0;
  }

  glfwInit();
  assert(init_window(argc, argv) >= 0);
  assert(init_vulkan(argc, argv) >= 0);

  GLFWwindow *win = get_window();
  for (;!glfwWindowShouldClose(win);) {
    glfwPollEvents();
  }
  return 0;
}
