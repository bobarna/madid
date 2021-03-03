#ifndef MADID_SCENE_H
#define MADID_SCENE_H

#include <iostream>

class Scene {
    bool draw_normals;
    bool draw_surface;
    bool draw_velocity;
    bool render;
    bool use_emitter;
    
public:
    Scene();
    ~Scene();

    void update(double dt);
    void render();
};

#endif
