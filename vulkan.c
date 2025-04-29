#include "vulkan_local.h"

VkInstance g_vkInstance;
VkPhysicalDevice g_vkPDev;
VkDevice g_vkDev;
QueueFamilies g_queueFamilies;

int init_vulkan(int argc, char **argv)
{
  if (!(g_vkInstance = create_instance())) return -1;
  if (!(g_surfase = create_surfase())) return -1;
  if (!(g_vkPDev = find_pdev())) return -1;
  if ((g_queueFamilies = find_queue_famalies()).graphics < 0) return -1;
  if (!(g_vkDev = create_dev())) return -1;
  vkGetDeviceQueue(g_vkDev, g_queueFamilies.graphics, 0, &g_vkGraphicQueue);
  vkGetDeviceQueue(g_vkDev, g_queueFamilies.present, 0, &g_vkGraphicQueue);
  return 0;
}
