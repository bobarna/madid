#ifndef MADID_SCENE_H
#define MADID_SCENE_H

#include <glm/glm.hpp>

namespace sph {
    class Particle {
        public:
            typedef glm::vec3 vector;
            typedef vector point_type;

            Particle();
        private:
            float radius; // radius of the particle
            float radius_sqr; // squared radius of the particle
            point_type pos; // position of the particle
            point_type old_pos; // old position of the particle
            vector v; // current velocity
            vector a; // current acceleration
            vector f; // current sum of external forces acting on the particle
            vector n; // surface normal if close to/on the surface, else 0
            float m; // mass (constant)
            float rho; // density (varies)
            float p; // pressure (varies)
            bool fixed; // Is this particled fixed (locked)?
        public:
            // will need these for hashing
            point_type min() const;
            point_type max() const;

            // checks if two particles (actually two positions) are within an
            // allowed radius.
            bool check(const point_type& candidate) const;

            // get position (read only)
            const point_type& position() const;
            // get position
            point_type& position();

            
    }
}

#endif
