#include "vulkan_local.h"

VkInstance vkInstance;
VkPhysicalDevice vkPDev;
VkDevice vkDev;

int init_vulkan(int argc, char **argv)
{
  if (!(vkInstance = create_instance()))
    return -1;
  return 0;
}
