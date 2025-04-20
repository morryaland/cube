#include "vulkan.h"
#include "vulkan_instance.h"

int init_vulkan(int argc, char **argv)
{
  int ret;
  if ((ret = create_instance()) < 0)
    return ret;
}
