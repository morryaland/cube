#include "vulkan_local.h"
#include <stdio.h>
#include <stdlib.h>

VkDevice create_dev()
{
  VkDevice dev;
  qf2a qfs;
  int qf_c = sizeof(QueueFamilies) / sizeof(long);
  qfs.qf = g_queueFamilies;
  VkDeviceQueueCreateInfo *info_devqs = malloc(qf_c * sizeof(VkDeviceQueueCreateInfo));
  for (int i = 0; i < qf_c; i++) {
    info_devqs[i].sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    info_devqs[i].queueFamilyIndex = qfs.array[i];
    info_devqs[i].queueCount = 1;
    info_devqs[i].pQueuePriorities = &(float){1.0f};
  }
  VkDeviceCreateInfo info_dev = {
    .sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
    .pQueueCreateInfos = info_devqs,
    .queueCreateInfoCount = qf_c,
    .pEnabledFeatures = NULL,
  };
  if (vkCreateDevice(g_vkPDev, &info_dev, NULL, &dev) != VK_SUCCESS) {
    fprintf(stderr, "ERR: failed to create device\n");
    return NULL;
  }
  return dev; 
}
