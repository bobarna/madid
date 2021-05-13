#ifndef MADID_TEXTURE_UNIFORM_COLOR_H
#define MADID_TEXTURE_UNIFORM_COLOR_H

#include "texture.h"

class UniformColorTexture : public Texture {
public:
    UniformColorTexture(float r = 1, float g = 1, float b = 0, float a = 1) : Texture() {
        std::vector<vec4> color;
        color.emplace_back(r, g, b, a);

        create(1, 1, color, GL_NEAREST);
    }
};


#endif //MADID_TEXTURE_UNIFORM_COLOR_H
