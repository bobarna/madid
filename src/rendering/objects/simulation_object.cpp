#include "simulation_object.h"

SimulationObject::SimulationObject(Shader *_shader, PBDSimulation *_sim):
    Object(_shader, _sim) {

}

void SimulationObject::ResetExternalForces() {

}

void SimulationObject::AddForce(glm::vec3 f) {
    reinterpret_cast<Simulation *>(geometry)->addForce(f);
}

void SimulationObject::update(float delta_t) {
    reinterpret_cast<Simulation *>(geometry)->update(delta_t);
}


