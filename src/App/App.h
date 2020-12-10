#ifndef APP_H
#define APP_H

#include <vector>
#include <optional>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;

    bool isComplete();
};

VkResult createDebugUtilsMessengerEXT(
    VkInstance,
    const VkDebugUtilsMessengerCreateInfoEXT*,
    const VkAllocationCallbacks*,
    VkDebugUtilsMessengerEXT*);

void destroyDebugUtilsMessengerEXT(
    VkInstance,
    VkDebugUtilsMessengerEXT,
    const VkAllocationCallbacks*);

class App {
public:
    void run();
private:
    GLFWwindow* window;
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    
    const uint32_t WIDTH = 1280;
    const uint32_t HEIGHT = 720;
    const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();

    void createInstance();
    void setupDebugMessenger();
    void pickPhysicalDevice();

    bool checkValidationLayerSupport();
    std::vector<const char*> getRequiredExtensions();
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT,
        VkDebugUtilsMessageTypeFlagsEXT,
        const VkDebugUtilsMessengerCallbackDataEXT*,
        void*
    );
    void populateDebugMessengerCreateInfo(
        VkDebugUtilsMessengerCreateInfoEXT&);

    bool isDeviceSuitable(VkPhysicalDevice);
    uint32_t rateDeviceSuitability(VkPhysicalDevice);

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice);
};

#endif