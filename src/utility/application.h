#ifndef MADID_APPLICATION_H
#define MADID_APPLICATION_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>

#include "constants.h"


class Application {
    bool dragging = false;
    int keyArr[350];

public:
    Application();
    ~Application();

};


#endif //MADID_APPLICATION_H
