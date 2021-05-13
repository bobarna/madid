#ifndef MADID_SIMULATION_OBJECT_H
#define MADID_SIMULATION_OBJECT_H

#include "object.h"
#include "../../simulation/pbd/pbd_simulation.h"

class SimulationObject : public Object {
public:
    SimulationObject(Shader *_shader, PBDSimulation *_sim);

    void ResetExternalForces();

    void AddForce(glm::vec3 f);

    void update(float delta_t) override;
};


#endif //MADID_SIMULATION_OBJECT_H
