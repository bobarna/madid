#ifndef MADID_PBD_SIMULATION_H
#define MADID_PBD_SIMULATION_H

#include <cstddef>
#include <vector>
#include <glm/glm.hpp>

#include "../../utility/gl.h"
#include "../particle.h"
#include "../../rendering/geometry.h"
#include "../simulation.h"

typedef glm::vec3 vec3;

class PBDSimulation : public Geometry {
    void solve_distance_constraint(Particle *p1, Particle *p2, float dist);

    void solve_bending_constraint(Particle *p1, Particle *p2, float dist);

    void solve_collision_constraint(Particle *p, vec3 &q1, vec3 &q2, vec3 &q3);

public:
    //// number of hair strands to be placed on the head
    size_t nrStrands;

    //// how many segments a strand will be sub-divided into
    size_t nrSegments;

    //// length of a segment
    float lSeg;

    ////
    std::vector<std::vector<Particle *>> strands;

    ////
    vec3 externalForces;

    ////
    std::vector<vec3> collisionTriangles;

    void addForce(vec3 force);

    PBDSimulation(size_t _nr_sims, size_t _nr_segments, float _l_seg);

    void update(float dt);

    void render() override;

    void resetExternalForces();

    std::vector<Particle *> CreateFiber(size_t n, float l, vec3 startPos, vec3 color);
};


#endif //MADID_PBD_SIMULATION_H
