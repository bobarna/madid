#include <cstdio>
#include "Drawable.h"

Drawable::Drawable() {
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
}

Drawable::~Drawable() {
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}
