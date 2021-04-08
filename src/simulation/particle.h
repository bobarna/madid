#ifndef MADID_PARTICLE
#define MADID_PARTICLE

#include <glm/glm.hpp>

class Particle {
public:
    typedef glm::vec3 vector;
    typedef vector point_type;

    Particle(float x, float y, float z);

    Particle(vector pos, float w, vector color);

    ~Particle();

    //TODO proper scope, maybe getter functions
public:
    point_type pos;     // position of the particle
    point_type old_pos; // old position of the particle
    float radius;       // radius of the particle
    float radius_sqr;   // squared radius of the particle
    vector v;           // current velocity
    vector a;           // current acceleration
    vector f;           // current sum of external forces acting on the particle
    vector n;           // surface normal if close to/on the surface, else 0
    float w;            // inverse mass (constant)
    vector tmp_pos;     // temporary position (for PBD simulation)
    vector color;       // (r,g,b) color of the particle
    float rho;          // density (varies)
    float p;            // pressure (varies)
    bool fixed;         // Is this particled fixed (locked)?
};

#endif
