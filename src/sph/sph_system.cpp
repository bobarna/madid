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
                float r = glm::l2Norm(p_j->pos, p_i->pos);
                float r2 = glm::pow(r, 2.f);
                
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

                glm::vec3 r_ijv = p_i->pos - p_j->pos;
                float r_ij = glm::length(r_ijv);
                
                if(r_ij <= H) {
                    // compute pressure force contribution

                    f_pressure += -M * (p_i->p + p_j->p) / (2*p_j->rho) *
                        POLY6_GRAD_PRESS * r_ijv/r_ij * glm::pow(H-r_ij, 2.0f);

                    f_viscosity += MU * M * (p_j->v - p_i->v) / p_j->rho *
                        POLY6_GRAD_VISC * (H - r_ij);
                }

                glm::vec3 f_gravity = G * p_i->rho;

//                p_i->f = f_pressure + f_viscosity + f_gravity;
                p_i->f = f_gravity + f_pressure;// * 0.001f;
            }
        }
    }

    void System::integrate() {
        for (auto &p : particles) {
            // forward euler
            p->v += DT * p->f / p->rho;
            p->pos += DT * p->v;

            const float max_b = 1.2f;
            const float min_b = 0.9f;

            //boundary conditions
            if (p->pos.x - EPS <= min_b) {
                p->v.x *= BOUND_DAMPING;
                p->pos.x = min_b + EPS;
            }

            if(p->pos.x + EPS > max_b) {
                p->v.x *= BOUND_DAMPING;
                p->pos.x = max_b - EPS;
            }

            // ground
            if(p->pos.y - EPS <= 0.0f) {
                p->v.y *= BOUND_DAMPING;
                p->pos.y = EPS;
            }

            if(p->pos.y + EPS >= 51) {
                p->v.y *= BOUND_DAMPING;
                p->pos.y = 51 - EPS;
            }

            //TODO DEPTH CONSTANT VALUE
            if(p->pos.z - EPS <= min_b) {
                p->v.z *= BOUND_DAMPING;
                p->pos.z = min_b + EPS;
            }

            if(p->pos.z + EPS >= max_b) {
                p->v.z *= BOUND_DAMPING;
                p->pos.z = max_b - EPS;
            }

            p->v *= 0.98;
        }
    }

    void System::update(float t) {
        compute_density_and_pressure();
        compute_forces();

//        if(t > DT)
//            for(float dt = 0.0f; dt < t; dt+=DT)
//                integrate();
//        else
            integrate();
    }

    void System::render() {
        // TODO MODERN OPENGL!!!!
        glEnable(GL_POINT_SMOOTH);
        glPointSize( 1.f);

        glColor4f(0.5f, 0.5f, 0.8f, 1.f);

        glBegin(GL_POINTS);
        for(auto &p : particles)
            glVertex3f(p->pos.x, p->pos.y, p->pos.z);
        glEnd();
        
    }
}
