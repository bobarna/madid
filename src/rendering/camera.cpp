#include <iostream>
#include "camera.h"

Camera::Camera():
    aspect_ratio(1),
    pos(1, 1, -3),
    forward(0,0,1),
    right(-1,0,0),
    speed(10) 
{
    inputHandler = InputHandler::GetInstance();
}

Camera::~Camera() {
}


void Camera::control(float delta_time) {
    // process camera keys
    if(InputHandler::IsPressed(GLFW_KEY_W))
        pos += forward * speed * delta_time;


    if(InputHandler::IsPressed(GLFW_KEY_S))
        pos -= forward * speed * delta_time;

    if(InputHandler::IsPressed(GLFW_KEY_A))
        pos -= right * speed * delta_time;

    if(InputHandler::IsPressed(GLFW_KEY_D))
        pos += right * speed * delta_time;

    if(InputHandler::IsPressed(GLFW_KEY_Q))
        pos += glm::vec3(0,-1,0) * speed * delta_time;

    if(InputHandler::IsPressed(GLFW_KEY_E))
        pos += glm::vec3(0,1,0) * speed * delta_time;

    std::cout << pos.x << pos.y << pos.z << std::endl;
}

void Camera::startDrag(int x, int y) {
   drag_start = glm::vec2(0,0);
}

void Camera::drag(int x, int y) {
    glm::vec2 d(drag_start.x - (float)x, drag_start.y - (float)y);
    
    forward = glm::normalize(forward);
    right = cross(forward, glm::vec3(0,1,0));
    right = glm::normalize(right);

    // TODO 
}


void Camera::glSetupCamera() const {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect_ratio, 1.0f, 1000.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            pos.x, pos.y, pos.z,
            pos.x + forward.x, pos.y + forward.y, pos.z + forward.z, 
            0.0f, 1.0f, 0.0f);
}

