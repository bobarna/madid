#ifndef MADID_SPH_SYSTEM
#define MADID_SPH_SYSTEM

#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>
#include <glm/gtx/norm.hpp>
#include <iostream>
#include <vector>

#include "../../utility/gl.h"

#include "../particle.h"
#include "../../constants.h"

namespace sph {
    // external (gravitational force)
    const static glm::vec3 G(0.f, -9.8f, 0.f);
    // rest density
    const static float REST_DENS = 1000.0f;
    // const for equation of state
    const static float GAS_CONST = 3.0f;
    // kernel radius
    const static float H = 0.0457f;
    // (kernel radius)^2 for optimization
    const static float H2 = H * H;
    // mass of particles
    const static float M = 0.02f;
    // viscosity constant
    const static float MU = 42.f;
    // TODO decide the place for this
    // integration timestep
    const static float DT = 0.01f;

    // epsilon (e.g. at boundary check)
    const static float EPS = 0.0001f;
    // damping when colliding with the boundary
    const static float BOUND_DAMPING = -0.5f;

    [[maybe_unused]] const static float PI = glm::pi<float>();
    // smoothing kernel as described in the Müller paper
    const static float POLY6 = 315.f / (64.f * glm::pi<float>() * glm::pow(H, 9));
    const static float POLY6_GRAD_PRESS = -45.f / (glm::pi<float>()
            * glm::pow(H, 6));
    const static float POLY6_GRAD_VISC = 45.f / (glm::pi<float>() * glm::pow(H,
                6));

    // PARTICLES
    // number of particles
    const static int N = 400;
}


class SPHSimulation {

    std::vector<Particle*> particles;
    
    void compute_density_and_pressure();
    void compute_forces();

    void integrate();

public:
    SPHSimulation();
    ~SPHSimulation();

    // step the system by t time
    void update(float t);

    void render();
};

#endif
