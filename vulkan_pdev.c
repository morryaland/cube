#include "vulkan_local.h"
#include <stdio.h>
#include <stdlib.h>

VkPhysicalDevice pdev;

VkPhysicalDevice find_pdev()
{
  unsigned int pdev_c;
  VkPhysicalDevice *pdevs;
  VkPhysicalDevice pdev;
  vkEnumeratePhysicalDevices(g_vkInstance, &pdev_c, NULL);
  if (!pdev_c) {
    fprintf(stderr, "ERR: supported device not found\n");
    return NULL;
  }
  pdevs = malloc(pdev_c * sizeof(VkPhysicalDevice));
  vkEnumeratePhysicalDevices(g_vkInstance, &pdev_c, pdevs);
  pdev = pdevs[0];
  return pdev;
}
