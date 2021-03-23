#include "particle.h"

namespace sph {

    Particle::Particle(float x, float y, float z):
        pos(x, y, z),
        old_pos(pos),
        radius(1), //TODO
        radius_sqr(1*1), //TODO
        v(0, 0, 0),
        a(0,0,0),
        f(0,0,0),
        n(0,0,0),
        m(1),
        rho(1),
        p(0),
        fixed(false)
    {
        
    }

    Particle::~Particle(){}

//    // will need these for hashing
//    Particle::point_type min() const {
//        return Particle::point_type(pos.x - Particle::point_type(radius));
//    }
//
//    Particle::point_type max() const {
//        return Particle::point_type(x + Particle::point_type(radius));
//    }
//
//    // checks if two particles (actually two positions) are within an
//    // allowed radius.
//    bool check(const point_type& candidate_pos) const{
//        Particle::point_type diff(pos - candidate_pos);
//        return radius_sqrt >= diff*diff;
//    }
//    // Position
//    const point_type& position() const;
//    point_type& position();
//
//    //Old Position
//    const point_type& old_pos() const { return old_pos; }
//    point_type& old_pos() { return old_pos; }
//
//    // Velocity
//    const vector &velocity() const { return v; }
//    vector &velocity() { return v; }
//
//    // Acceleration
//    const vector &acceleration() const { return a; }
//    vector &acceleration() { return a; }
//
//    // Force
//    const vector &force() const { return f; }
//    vector &force() { return f; }
//
//    // Mass
//    const float &mass() const { return m; }
//    float &mass() { return m; }
//
//    // Density
//    const float &density() const { return rho; }
//    float &density() { return rho; }
//
//    // Pressure
//    const float &pressure() const { return p; }
//    float &pressure() { return p; }
//
//    // Normal vector of the surface
//    const vector &normal() const { return n; }
//    vector &normal() { return n; }
//
//    // Fixed flag of the particle
//    const bool &fixed() const { return fixed; }
//    bool &fixed() { return fixed; }
//
//    // Radius of the particle
//    const float &radius() const { return radius; }

}
