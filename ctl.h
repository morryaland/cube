#ifndef __CTL_H__
#define __CTL_H__

#define CTLZERO_MODE 1
#define CTLRESIZE 2

typedef struct {
  unsigned int flags;
  unsigned int width;
  unsigned int height;
  char title[255];

} ctl_t;

void help_menu();

ctl_t parse_args(int argc, char **argv);

#endif
