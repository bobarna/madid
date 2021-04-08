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
    bool use_emitter;

    std::shared_ptr<SPHSimulation> sph_system = std::make_shared<SPHSimulation>();

    // TODO set parameters here
    std::shared_ptr<PBDSimulation> pbd_system = std::make_shared<PBDSimulation>();

public:
    Scene();

    ~Scene();

    void update(double dt);

    void render();
};

#endif
