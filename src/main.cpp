// Math
#include <glm/glm.hpp>

#include <iostream>
#include <memory>

#include "application.h"
#include "constants.h"


int main(int argc, char **argv) {

    // start GL context and O/S window using the GLFW helper library
    if (!glfwInit()) {
        std::cerr << "ERROR: could not start GLFW3" << std::endl;
        return 1;
    }

    /* Creating a GLFW application */
    /* Application creates its GLFW window too */
    std::shared_ptr<Application> application = std::make_shared<Application>();
    
    if(!application->window) {
        std::cerr << "ERROR: could not open window with GLFW3" << std::endl;
        glfwTerminate();
        return 1;
    }
    
    glfwMakeContextCurrent(application->get_window());
    
    // start GLEW extension handler
    glewExperimental = GL_TRUE;
    glewInit();

    // get version info
    const GLubyte *renderer = glGetString(GL_RENDERER); // get renderer string
    const GLubyte *version = glGetString(GL_VERSION); // version as a string
    std::cerr << "Renderer: " << renderer << std::endl;
    std::cerr << "OpenGL version supported: " << version << std::endl;

    application->init();
    
    application->start();

}
