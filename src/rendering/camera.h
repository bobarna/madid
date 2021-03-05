#ifndef MADID_CAMERA_H
#define MADID_CAMERA_H

#include <glm/glm.hpp>
#include "../utility/gl.h"
#include "../utility/InputHandler.h"

class Camera {
    float aspect_ratio;
    glm::vec3 pos;
    glm::vec3 forward;
    glm::vec3 right;
    float speed;

    InputHandler* inputHandler;

    glm::vec2 drag_start = glm::vec2(0,0);
public:
    void setAspectRatio(float ar) {
        aspect_ratio = ar;
    }

    void control(float delta_time);
    void startDrag(int x, int y);
    void drag(int x, int y);

    void glSetupCamera() const;

    Camera();
    ~Camera();

};

#endif
