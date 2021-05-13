#ifndef MADID_SCENE_H
#define MADID_SCENE_H

#include <iostream>
#include <memory>

#include "rendering/objects/object.h"
#include "rendering/objects/simulation_object.h"
#include "rendering/camera.h"

class Scene {
    bool draw_normals;
    bool draw_surface;
    bool draw_velocity;
    bool use_emitter;

    std::shared_ptr<Camera> camera = std::make_shared<Camera>();

    // TODO shared_ptr
    std::vector<std::shared_ptr<SimulationObject>> simulations;

public:
    Scene();

    ~Scene();

    void update(double dt);

    void render();
};

#endif
