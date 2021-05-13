#include "basic_shader.h"

BasicShader::BasicShader() {
    create(vertexCode, fragmentCode, "fragmentColor");
}

void BasicShader::Bind(RenderState state) {
    Use(); //make this program run
    setUniform(state.MVP, "MVP");
}