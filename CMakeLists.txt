cmake_minimum_required(VERSION 3.16)
project(VulkanRender VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} src/VulkanRender/main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(dependencies/glfw)

target_include_directories(${PROJECT_NAME} PUBLIC dependencies/glfw/include)

add_subdirectory(dependencies/glm)

target_include_directories(${PROJECT_NAME} PUBLIC dependencies/glm/glm)


add_subdirectory(src)