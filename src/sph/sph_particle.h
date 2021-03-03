#ifndef MADID_SPH_PARTICLE
#define MADID_SPH_PARTICLE

#include <glm/glm.hpp>

namespace sph {
class Particle {
    public:
        typedef glm::vec3 vector;
        typedef vector point_type;

        Particle();
    private:
        float radius;       // radius of the particle
        float radius_sqr;   // squared radius of the particle
        point_type pos;     // position of the particle
        point_type old_pos; // old position of the particle
        vector v;           // current velocity
        vector a;           // current acceleration
        vector f;           // current sum of external forces acting on the particle
        vector n;           // surface normal if close to/on the surface, else 0
        float m;            // mass (constant)
        float rho;          // density (varies)
        float p;            // pressure (varies)
        bool fixed;         // Is this particled fixed (locked)?
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

        /** Old Position (read only).
        * @return  const reference to the old position vector.
        */
        const point_type& old_pos() const;

        /** Old Position.
        * @return  reference to the old position vector.
        */
        point_type& old_pos();

        /** Velocity (read only).
        * @return  const reference to the velocity vector.
        */
        const vector &velocity() const;

        /** Velocity.
        * @return  reference to the velocity vector.
        */
        vector &velocity();

        /** Acceleration (read only).
        * @return  const reference to the acceleration vector.
        */
        const vector &acceleration() const;

        /** Acceleration.
        * @return  reference to the acceleration vector.
        */
        vector &acceleration();

        /** Force (read only).
        * @return  const reference to the external force vector.
        */
        const vector &force() const;

        /** Force.
        * @return  reference to the external force vector.
        */
        vector &force();

        /** Mass (read only).
        * @return  const reference to the mass scalar.
        */
        const float &mass() const;

        /** Mass.
        * @return  reference to the mass scalar.
        */
        float &mass();

        /** Density (read only).
        * @return  const reference to the density value.
        */
        const float &density() const;

        /** Density.
        * @return  reference to the density value.
        */
        float &density();

        /** Pressure (read only).
        * @return  const reference to the pressure value.
        */
        const float &pressure() const;

        /** Pressure.
        * @return  reference to the pressure value.
        */
        float &pressure();

        /** Normal (read only).
        * @return  const reference to the surface normal.
        */
        const vector &normal() const;

        /** Normal.
        * @return  reference to the surface normal.
        */
        vector &normal();

        /** Fixed (read only).
        * @return  const reference to the surface normal.
        */
        const bool &fixed() const;

        /** Fixed.
        * @return  reference to the surface normal.
        */
        bool &fixed();

        /** Fixed.
        * @return  reference to the surface normal.
        */
        const float &radius() const;
        
}
}

#endif
