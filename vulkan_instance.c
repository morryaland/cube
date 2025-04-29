#include "vulkan_local.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

VkInstance create_instance()
{
  VkInstance inst;
  unsigned int ext_c;
  char **ext;
  if (!glfwVulkanSupported()) {
    fprintf(stderr, "ERR: Vulkan unsupported\n");
    return NULL;
  }
  ext = (char**)glfwGetRequiredInstanceExtensions(&ext_c);
  VkApplicationInfo info_app = {
    .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
    .apiVersion = VK_API_VERSION_1_4,
    .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
    .engineVersion = VK_MAKE_VERSION(1, 0, 0),
    .pApplicationName = "myapp",
    .pEngineName = "myapp",
  };
  VkInstanceCreateInfo info_inst = {
    .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
    .pApplicationInfo = &info_app,
    .enabledExtensionCount = ext_c,
    .ppEnabledExtensionNames = (const char**)ext,
  };
  if (vkCreateInstance(&info_inst, NULL, &inst) != VK_SUCCESS) {
    fprintf(stderr, "ERR: failed to create Instance\n");
    return NULL;
  }
  return inst;
}
