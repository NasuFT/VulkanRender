add_library(App 
    App/App.h 
    App/App.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC App)

find_package(Vulkan REQUIRED)
target_link_libraries(App PRIVATE Vulkan::Vulkan)
target_link_libraries(App PRIVATE glfw)

target_link_libraries(${PROJECT_NAME} PRIVATE App)

target_compile_definitions(${PROJECT_NAME} PRIVATE VK_USE_PLATFORM_WIN32_KHR)
target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Vulkan)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

target_link_libraries(${PROJECT_NAME} PRIVATE glm)