#ifndef MADID_SCENE_H
#define MADID_SCENE_H

#include <iostream>
#include <memory>

#include "simulation/sph/sph_simulation.h"
#include "simulation/pbd/pbd_simulation.h"

class Scene {
    bool draw_normals;
    bool draw_surface;
    bool draw_velocity;
//    bool render;
    bool use_emitter;

    std::shared_ptr<sph::SPHSimulation> sph_system = std::make_shared<sph::SPHSimulation>();
    
public:
    Scene();
    ~Scene();

    void update(double dt);
    void render();
};

#endif
