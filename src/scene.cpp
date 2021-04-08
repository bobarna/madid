#include "scene.h"

Scene::Scene() {
    std::cout << "Scene built successfully" << std::endl;
}

Scene::~Scene() {
    std::cout << "Scene destroyed" << std::endl;
}

void Scene::update(double dt) {
    sph_system->update((float) dt);
}

void Scene::render() {
    sph_system->render();
}
