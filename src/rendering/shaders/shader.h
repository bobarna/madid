#ifndef MADID_SHADER_H
#define MADID_SHADER_H

#include "gpu_program.h"
#include "../render_state.h"
#include "../materials/material.h"
#include "../lights/light.h"

class Shader : public GPUProgram {
public:
    virtual void Bind(RenderState state) = 0;

    void setUniformMaterial(Material &material, const std::string &name);

    void setUniformLight(const Light &light, const std::string &name);
};


#endif //MADID_SHADER_H
