#include "ctl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

void help_menu()
{
    puts(
"  -r\t\tresize mode\n"
"  -w\t\twidth\n"
"  -h\t\theight\n"
"  -t\t\ttitle\n"
"  -d\tzero/opengl/vulkan\n"
"  --help\tthis help\n"
    );
    exit(0);
}

ctl_t parse_args(int argc, char **argv)
{
  ctl_t ctl = {};
  ctl.flags |= CTLZERO_MODE;
  char c;
  int opt = -1;
  struct option opts[] = {{"help", 0, 0, 0}, {}};
  while ((c = getopt_long(argc, argv, "w:h:t:rd:", opts, &opt)) > 0) {
    switch (opt) {
      case 0:
        help_menu();
      case 1:
        break;
    }
    switch (c) {
      case 'w':
        sscanf(optarg, "%d", &ctl.width);
        break;
      case 'h':
        sscanf(optarg, "%d", &ctl.height);
        break;
      case 't':
        strcpy(ctl.title, optarg);
        break;
      case 'r':
        ctl.flags |= CTLRESIZE;
        break;
      case 'd':
               if (!strcmp(optarg, "zero")) {
          ctl.flags |= CTLZERO_MODE;
          ctl.flags &= !CTLVULKAN;
        } else if (!strcmp(optarg, "opengl"))
          ctl.flags &= !CTLVULKAN && !CTLZERO_MODE;
          else if (!strcmp(optarg, "vulkan")) {
          ctl.flags |= CTLVULKAN;
          ctl.flags &= !CTLZERO_MODE;
        }
      default:
        fprintf(stderr, "ERR: symbol not found\n");
        exit(-1);
    }
  }
  return ctl;
}
