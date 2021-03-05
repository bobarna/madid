#include "sph_system.h"

namespace sph {

    System::System() {
        std::cout << "Initializing sph particle system with " << N <<
            " particles." << std::endl;

        for(float y = 1; y < 5; y += 0.5f)
            for(float z = 0; z < 2; z += 0.2f)
                for (float x = 0; x < 2; x += 0.2f)
                    if (particles.size() < N)
                    {
                        float x_off = glm::linearRand(.0f, 1.f);
                        particles.emplace_back(new Particle(x + x_off, y, z));
                    }

        std::cout << "There are " << particles.size() << "particles." <<
            std::endl;
    }

    System::~System() {
        for(auto & particle : particles)
            delete particle;

    }

    void System::compute_density_and_pressure() {
        for(auto &p_i : particles) {
            // compute density
            p_i->rho = 0.f;
            for(auto &p_j : particles) {
                glm::vec3 r_ij = p_j->pos - p_i->pos;
                // euclidean distance between p_i and p_j
                float r2 = glm::l2Norm(p_j->pos, p_i->pos);
                
                // 0 <= r <= d
                if (r2 <= H2)
                    p_i->rho += M * POLY6 * glm::pow(H2 - r2, 3.f);
            }
            
            // compute pressure
            p_i->p = GAS_CONST * (p_i->rho - REST_DENS);
        }

    }

    void System::compute_forces() {
        for (auto &p_i : particles) {
            glm::vec3 f_pressure(0.f, 0.f, 0.f);
            glm::vec3 f_viscosity(0.f, 0.f, 0.f);

            for(auto &p_j : particles) {
                if(&p_i == &p_j) continue;

                float r_ij = glm::length(p_j->pos - p_i->pos);
                
                if(r_ij <= H) {
                    // compute pressure force contribution
                    f_pressure += -M * r_ij / (2*p_j->rho) *
                        POLY6_GRAD_PRESS * glm::pow(H - r_ij, 2.f);
                    f_viscosity += MU * M * (p_j->v - p_i->v) / p_j->rho *
                        POLY6_GRAD_VISC * (H - r_ij);
                }

                glm::vec3 f_gravity = G * p_i->rho;

                p_i->f = f_pressure + f_viscosity + f_gravity;
            }
        }
    }

    void System::integrate() {
        for (auto &p : particles) {
            // forward euler
            p->v += DT * p->f / p->rho;
            p->pos += DT * p->v;

            //boundary conditions
            if (p->pos.x - EPS <= 0) {
                p->v.x *= BOUND_DAMPING;
                p->pos.x = EPS;
            }

            if(p->pos.x + EPS > 2) {
                p->v.x *= BOUND_DAMPING;
                p->pos.x = 2 - EPS;
            }

            if(p->pos.y - EPS <= 0) {
                p->v.y *= BOUND_DAMPING;
                p->pos.y = EPS;
            }

            if(p->pos.y + EPS >= 51) {
                p->v.y *= BOUND_DAMPING;
                p->pos.y = 51 - EPS;
            }

            //TODO DEPTH CONSTANT VALUE
            if(p->pos.z - EPS <= 0) {
                p->v.z *= BOUND_DAMPING;
                p->pos.z = EPS;
            }

            if(p->pos.z + EPS >= 2) {
                p->v.z *= BOUND_DAMPING;
                p->pos.z = 2 - EPS;
            }
        }
    }

    void System::update(float t) {
        compute_density_and_pressure();
        compute_forces();

        if(t > DT)
            for(float dt = 0.0f; dt < t; dt+=DT)
                integrate();
        else
            integrate();
    }

    void System::render() {
        // TODO MODERN OPENGL!!!!
        glEnable(GL_POINT_SMOOTH);
        glPointSize(H / 2.f);

        glColor4f(0.5f, 0.5f, 0.8f, 1.f);

        glBegin(GL_POINTS);
        for(auto &p : particles)
            glVertex3f(p->pos.x, p->pos.y, p->pos.z);
        glEnd();
        
    }
}
