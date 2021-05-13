#include "scene.h"
#include "rendering/shaders/basic_shader.h"

Scene::Scene() {
    camera->glSetupCamera();

    size_t nrSims = 100;
    size_t nrSegments = 50;
    float lSeg = 0.003f;

    auto pbd_sim = new PBDSimulation(nrSims, nrSegments, lSeg);

    Shader *basicShader = new BasicShader();

    auto pbd_sim_object = std::make_shared<SimulationObject>(basicShader, pbd_sim);

    simulations.push_back(pbd_sim_object);

    std::cout << "Scene built successfully." << std::endl;
}

Scene::~Scene() {
    std::cout << "Scene destroyed." << std::endl;
}

void Scene::update(double dt) {
    camera->control(dt);

    for (auto &s: simulations) s->update(dt);
}

void Scene::render() {
    camera->glSetupCamera();
    for (auto &s: simulations) s->render(camera->getState());
}
