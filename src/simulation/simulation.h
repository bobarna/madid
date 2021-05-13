#ifndef MADID_SIMULATION_H
#define MADID_SIMULATION_H


#include "../rendering/geometry.h"

class Simulation : public Geometry {
public:
    virtual void addForce(glm::vec3 force) = 0;
    Simulation(): Geometry() { };

    virtual void update(float dt) = 0;
    virtual void render() = 0;

    virtual void resetExternalForces() = 0;
};


#endif //MADID_SIMULATION_H
