#ifndef MADID_PBD_SYSTEM_H
#define MADID_PBD_SYSTEM_H

#include <cstddef>
#include <vector>
#include <glm/glm.hpp>

#include "../particle.h"

typedef glm::vec3 vec3;

class pbd_system {
    void solve_distance_constraint(Particle *p1, Particle *p2, float dist);

    void solve_bending_constraint(Particle *p1, Particle *p2, float dist);

    void solve_collision_constraint(Particle *p, vec3 &q1, vec3 &q2, vec3 &q3);

public:
    //// mid-point of the head
    HeadObject *head;

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

    PBDSimulation(HeadObject *_head, size_t _nr_sims, size_t _nr_segments, float _l_seg);

    void propagateHead();

    void update(float dt);

    void Draw();

    vec3 getExternalForces() const;

    void resetExternalForces();

    std::vector<Particle *> CreateStrand(size_t segments, float l, vec3 startPos, vec3 color);
};


#endif //MADID_PBD_SYSTEM_H
