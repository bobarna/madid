cmake_minimum_required(VERSION 3.1)
project(madid)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -pedantic")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Wunused-parameter")
set(OpenGL_GL_PREFERENCE "LEGACY")

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/constants.h 
        src/utility/gl.h
        src/application.cpp
        src/application.h
        src/scene.cpp
        src/scene.h
        src/rendering/camera.cpp
        src/rendering/camera.h
        src/utility/input_handler.h
        src/utility/input_handler.cpp

        src/simulation/particle.cpp
        src/simulation/particle.h
        src/simulation/pbd/pbd_simulation.cpp
        src/simulation/pbd/pbd_simulation.h
        src/simulation/sph/sph_simulation.cpp
        src/simulation/sph/sph_simulation.h

        src/rendering/geometry.cpp src/rendering/geometry.h
        src/rendering/vertex_data.cpp src/rendering/vertex_data.h
        src/rendering/objects/object.cpp src/rendering/objects/object.h src/rendering/objects/simulation_object.cpp src/rendering/objects/simulation_object.h src/simulation/simulation.h src/utility/custom_math.h src/rendering/render_state.h src/rendering/textures/texture.cpp src/rendering/textures/texture.h src/rendering/shaders/shader.cpp src/rendering/shaders/shader.h src/rendering/shaders/gpu_program.cpp src/rendering/shaders/gpu_program.h src/rendering/textures/texture_uniform_color.h src/rendering/materials/material.h src/rendering/lights/light.cpp src/rendering/lights/light.h src/rendering/shaders/basic_shader.cpp src/rendering/shaders/basic_shader.h)


# opengl
find_package(OpenGL REQUIRED)

link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

target_link_libraries(
        ${PROJECT_NAME}
        GL
        GLU
        glfw
        GLEW
)

