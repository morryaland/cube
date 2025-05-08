#include "ctl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

void help_menu()
{
    puts(
"  -r\tresize mode\n"
"  -w #\twindow width\n"
"  -h #\twindow height\n"
"  -t <title>\twindow title\n"
"  -d <zero/opengl>\tgraphics backend\n"
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
  while ((c = getopt_long(argc, argv, "w:h:t:rd:", opts, &opt)) >= 0) {
    switch (opt) {
      case 0:
        help_menu();
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
        } else if (!strcmp(optarg, "opengl"))
          ctl.flags &= !CTLZERO_MODE;
          else
          fprintf(stderr, "ERR: %s not found\n", optarg);
      case '?':
        fprintf(stderr, "ERR: parameter was missed\n");
        exit(-1);
      default:
        fprintf(stderr, "ERR: parse with char: %c\n", c);
        exit(-1);
    }
  }
  return ctl;
}
