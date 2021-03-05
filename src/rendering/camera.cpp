#include "camera.h"

Camera::Camera():
    aspect_ratio(1),
    pos(0, 25, -50),
    forward(0,0,1),
    right(-1,0,0),
    speed(10) 
{
}

Camera::~Camera() {
}


void Camera::control(float delta_time, const bool* inputs) {
    // process camera keys
    for(int i = 0; i < 256; i++) {
        if(!inputs[i]) continue;
        switch(i)
        {
            case 'w': pos += forward * speed * delta_time; break;
            case 's': pos -= forward * speed * delta_time; break;
            case 'a': pos -= right * speed * delta_time; break;
            case 'd': pos += right * speed * delta_time; break;
            case 'q': pos += glm::vec3(0,-1,0) * speed * delta_time; break;
            case 'e': pos += glm::vec3(0,1,0) * speed * delta_time; break;
            default: break;
        }
    }
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

