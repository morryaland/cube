#ifndef __VULKAN_LOCAL_H__
#define __VULKAN_LOCAL_H__

#include "window.h"
#include <vulkan/vulkan.h>

typedef struct {
  long graphics;
  long present;
} QueueFamilies;

typedef union {
  long *array;
  QueueFamilies qf;
} qf2a;

extern VkInstance g_vkInstance;
extern VkPhysicalDevice g_vkPDev;
extern VkDevice g_vkDev;
extern VkQueue g_vkGraphicQueue;
extern QueueFamilies g_queueFamilies;

int init_vulkan(int argc, char **argv);

VkInstance create_instance();

VkPhysicalDevice find_pdev();

QueueFamilies find_queue_famalies();

VkDevice create_dev();



#endif
