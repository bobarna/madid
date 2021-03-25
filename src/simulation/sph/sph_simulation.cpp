#include "sph_simulation.h"

    SPHSimulation::SPHSimulation() {
        std::cout << "Initializing sph particle system with " <<sph::N<<
            " particles." << std::endl;

        for(float y = 1; y < 5; y += 0.5f)
            for(float z = 0; z < 2; z += 0.2f)
                for (float x = 0; x < 2; x += 0.2f)
                    if (particles.size() < sph::N)
                    {

                        float x_off = glm::linearRand(.0f, 1.f);
//                        particles.emplace_back(new Particle(x + x_off, y, z));
                        particles.emplace_back(
                                new Particle(
                                        glm::linearRand(1.f, 1.1f),
                                        glm::linearRand(1.f, 1.1f),
                                        glm::linearRand(1.f, 1.1f)
                                        )
                                );
                    }

        std::cout << "There are " << particles.size() << "particles." <<
            std::endl;
    }

    SPHSimulation::~SPHSimulation() {
        for(auto & particle : particles)
            delete particle;

    }

    void SPHSimulation::compute_density_and_pressure() {
        for(auto &p_i : particles) {
            // compute density
            p_i->rho = 0.f;
            for(auto &p_j : particles) {
                glm::vec3 r_ij = p_j->pos - p_i->pos;
                // euclidean distance between p_i and p_j
                float r = glm::l2Norm(p_j->pos, p_i->pos);
                float r2 = glm::pow(r, 2.f);
                
                // 0 <= r <= d
                if (r2 <= sph::H2)
                    p_i->rho += sph::M * sph::POLY6 * glm::pow(sph::H2 - r2, 3.f);
            }
            
            // compute pressure
            p_i->p = sph::GAS_CONST * (p_i->rho - sph::REST_DENS);
        }

    }

    void SPHSimulation::compute_forces() {
        for (auto &p_i : particles) {
            glm::vec3 f_pressure(0.f, 0.f, 0.f);
            glm::vec3 f_viscosity(0.f, 0.f, 0.f);

            for(auto &p_j : particles) {
                if(&p_i == &p_j) continue;

                glm::vec3 r_ijv = p_i->pos - p_j->pos;
                float r_ij = glm::length(r_ijv);
                
                if(r_ij <= sph::H) {
                    // compute pressure force contribution

                    f_pressure += -sph::M * (p_i->p + p_j->p) / (2*p_j->rho) *
                        sph::POLY6_GRAD_PRESS * r_ijv/r_ij * glm::pow(sph::H-r_ij, 2.0f);

                    f_viscosity += sph::MU * sph::M * (p_j->v - p_i->v) / p_j->rho *
                        sph::POLY6_GRAD_VISC * (sph::H - r_ij);
                }

                glm::vec3 f_gravity = sph::G * p_i->rho;

                p_i->f = f_pressure + f_viscosity + f_gravity;
                p_i->f = f_gravity + f_pressure;// * 0.001f;
            }
        }
    }

    void SPHSimulation::integrate() {
        for (auto &p : particles) {
            // forward euler
            p->v += sph::DT * p->f / p->rho;
            p->pos += sph::DT * p->v;

            const float max_b = 1.2f;
            const float min_b = 0.9f;

            //boundary conditions
            if (p->pos.x - sph::EPS <= min_b) {
                p->v.x *= sph::BOUND_DAMPING;
                p->pos.x = min_b + sph::EPS;
            }

            if(p->pos.x + sph::EPS > max_b) {
                p->v.x *= sph::BOUND_DAMPING;
                p->pos.x = max_b - sph::EPS;
            }

            // ground
            if(p->pos.y - sph::EPS <= 0.0f) {
                p->v.y *= sph::BOUND_DAMPING;
                p->pos.y = sph::EPS;
            }

            if(p->pos.y + sph::EPS >= 51) {
                p->v.y *= sph::BOUND_DAMPING;
                p->pos.y = 51 - sph::EPS;
            }

            //TODO DEPTH CONSTANT VALUE
            if(p->pos.z - sph::EPS <= min_b) {
                p->v.z *= sph::BOUND_DAMPING;
                p->pos.z = min_b + sph::EPS;
            }

            if(p->pos.z + sph::EPS >= max_b) {
                p->v.z *= sph::BOUND_DAMPING;
                p->pos.z = max_b - sph::EPS;
            }

            p->v *= 0.98;
        }
    }

    void SPHSimulation::update(float t) {
        compute_density_and_pressure();
        compute_forces();

//        if(t > sph::DT)
//            for(float dt = 0.0f; dt < t; dt+=sph::DT)
//                integrate();
//        else
            integrate();
    }

    void SPHSimulation::render() {
        // TODO MODERN OPENGL!!!!
        glEnable(GL_POINT_SMOOTH);
        glPointSize( 1.f);

        glColor4f(0.5f, 0.5f, 0.8f, 1.f);

        glBegin(GL_POINTS);
        for(auto &p : particles)
            glVertex3f(p->pos.x, p->pos.y, p->pos.z);
        glEnd();
        
    }
