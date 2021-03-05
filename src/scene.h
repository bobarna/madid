#ifndef MADID_SCENE_H
#define MADID_SCENE_H

#include <iostream>
#include <memory>

#include "sph/sph_system.h"

class Scene {
    bool draw_normals;
    bool draw_surface;
    bool draw_velocity;
//    bool render;
    bool use_emitter;

    std::shared_ptr<sph::System> sph_system = std::make_shared<sph::System>();
    
public:
    Scene();
    ~Scene();

    void update(double dt);
    void render();
};

#endif
