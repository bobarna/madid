#include "particle.h"

Particle::Particle(float x, float y, float z) :
        pos(x, y, z),
        old_pos(pos),
        radius(1), //TODO
        radius_sqr(1 * 1), //TODO
        v(0, 0, 0),
        a(0, 0, 0),
        f(0, 0, 0),
        n(0, 0, 0),
        w(0), // inverse mass, 1/inf is 0
        rho(1),
        p(0),
        fixed(false) {
}

Particle::~Particle() {}

Particle::Particle(Particle::vector pos, float w, Particle::vector color) :
        pos(pos),
        w(w),
        color(color) {

}
