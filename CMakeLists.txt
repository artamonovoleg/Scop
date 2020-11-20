cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME Scop)

project(${PROJECT_NAME})

add_compile_options(
        -g
        -Wall
#        -Wextra
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)
set(INCLUDES    libs/glad/include
                libs/glfw/include
                libs/glm
                libs/stb_image
                libs/imgui
                libs/imgui/backends)

set(SRCS    libs/glad/src/glad.c
            libs/stb_image/stb_image.cpp
            src/Shader.cpp
            src/Texture.cpp

        libs/imgui/imconfig.h
        libs/imgui/imgui_demo.cpp
        libs/imgui/imgui_draw.cpp
        libs/imgui/imgui_impl_glfw.cpp
        libs/imgui/imgui_impl_glfw.h
        libs/imgui/imgui_impl_opengl3.cpp
        libs/imgui/imgui_impl_opengl3.h
        libs/imgui/imgui_internal.h
        libs/imgui/imgui_widgets.cpp
        libs/imgui/imgui.cpp
        libs/imgui/imgui.h
        libs/imgui/imstb_rectpack.h
        libs/imgui/imstb_textedit.h
        libs/imgui/imstb_truetype.h
            main.cpp)

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
            GL X11 pthread dl)
endif()