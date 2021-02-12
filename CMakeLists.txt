cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME Scop)

project(${PROJECT_NAME})

add_compile_options(
        -g
        -Wall
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)

set(INCLUDES    third_party/glad/include
                third_party/glfw/include
                third_party/glm
                third_party/stb_image
                third_party/imgui/backends
                third_party/imgui)

set(SRCS    third_party/glad/src/glad.c
            third_party/stb_image/stb_image.cpp
            third_party/imgui/backends/imgui_impl_glfw.cpp
            third_party/imgui/backends/imgui_impl_opengl3.cpp
            third_party/imgui/imgui_widgets.cpp
            third_party/imgui/imgui_draw.cpp
            third_party/imgui/imgui_tables.cpp
            third_party/imgui/imgui_demo.cpp
            third_party/imgui/imgui.cpp

            src/Shader.cpp
            src/Texture.cpp
            src/Mesh.cpp
            src/Model.cpp
            src/App.cpp
            src/main.cpp)

include_directories(${INCLUDES})

add_executable(${PROJECT_NAME} ${SRCS})

link_directories(${INCLUDES}
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/glad
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/src)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} glfw glu32 opengl32)
elseif(APPLE)
    find_library(COCOA_Framework Cocoa)
    find_library(OpenGL_Framework OpenGL)
    find_library(IOKit_Framework IOKit)
    find_library(CoreVideo_Framework CoreVideo)

    target_link_libraries(${PROJECT_NAME}
            glfw
            ${COCOA_Framework} ${OpenGL_Framework}
            ${IOKit_Framework} ${CoreVideo_Framework})
elseif(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME}
            glfw
            GL X11 pthread dl tinyobjloader)
endif()