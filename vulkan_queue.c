#include "vulkan_local.h"
#include <stdlib.h>

QueueFamilies find_queue_famalies()
{
  QueueFamilies qFam;
  unsigned int qf_c = {-1};
  VkQueueFamilyProperties *qfs;
  VkBool32 presentSupport;
  vkGetPhysicalDeviceQueueFamilyProperties(g_vkPDev, &qf_c, NULL);
  qfs = malloc(qf_c * sizeof(VkQueueFamilyProperties));
  vkGetPhysicalDeviceQueueFamilyProperties(g_vkPDev, &qf_c, qfs);
  for (int i = 0; i < qf_c; i++) {
    if (qfs[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
      qFam.graphics = i;
    }
    vkGetPhysicalDeviceSurfaceSupportKHR(g_vkPDev, i, g_surfase, &presentSupport);
    if (presentSupport)
      qFam.present = i;
  }
  return qFam;
}
