#ifndef MADID_SCENE_H
#define MADID_SCENE_H

#include <glm/glm.hpp>
#include "utility/gl.h"

class Camera {
    float aspect_ratio;
    glm::vec3 pos;
    glm::vec3 forward;
    glm::vec3 right;
    float speed;

    glm::vec2 drag_start(0,0);
public:
    void setAspectRatio(float ar) {
        aspect_ratio = ar;
    }

    void control(float delta_time, bool* inputs);
    void startDrag(int x, int y);
    void drag(int x, int y);

    void glSetupCamera();

    Camera(void);
    ~Camera(void);

}

#endif
