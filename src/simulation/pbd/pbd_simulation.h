#ifndef MADID_PBD_SIMULATION_H
#define MADID_PBD_SIMULATION_H

#include <cstddef>
#include <vector>
#include <glm/glm.hpp>

#include "../particle.h"

typedef glm::vec3 vec3;

class PBDSimulation {
    void solve_distance_constraint(Particle *p1, Particle *p2, float dist);

    void solve_bending_constraint(Particle *p1, Particle *p2, float dist);

    void solve_collision_constraint(Particle *p, vec3 &q1, vec3 &q2, vec3 &q3);

public:
    //// numberOfParticlesOnASide X numberOfParticlesOnASide sized cloth will be generated
    size_t numberOfParticlesOnASide;

    //// how many segments one side of the cloth will be subdivided into
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

    void initParticles();

    void update(float dt);

    void Draw();

    vec3 getExternalForces() const;

    void resetExternalForces();

    std::vector<Particle *> CreateStrand(size_t segments, float l, vec3 startPos, vec3 color);
};


#endif //MADID_PBD_SIMULATION_H
