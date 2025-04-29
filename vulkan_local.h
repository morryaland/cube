#ifndef __VULKAN_LOCAL_H__
#define __VULKAN_LOCAL_H__

#include "window.h"
#include <vulkan/vulkan.h>

extern VkInstance vkInstance;
extern VkPhysicalDevice vkPDev;
extern VkDevice vkDev;

int init_vulkan(int argc, char **argv);

VkInstance create_instance();

VkPhysicalDevice find_pdev();

#endif
