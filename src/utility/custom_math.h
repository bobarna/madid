#ifndef MADID_CUSTOM_MATH_H
#define MADID_CUSTOM_MATH_H

#include <glm/glm.hpp>
#include <cmath>
#include <vector>

using namespace glm;

inline mat4 translate_matrix(vec3 t) {
    return mat4(vec4(1, 0, 0, 0),
                vec4(0, 1, 0, 0),
                vec4(0, 0, 1, 0),
                vec4(t.x, t.y, t.z, 1));
}

inline mat4 scale_matrix(vec3 s) {
    return mat4(vec4(s.x, 0, 0, 0),
                vec4(0, s.y, 0, 0),
                vec4(0, 0, s.z, 0),
                vec4(0, 0, 0, 1));
}

inline mat4 rotation_matrix(float angle, vec3 w) {
    float c = cosf(angle), s = sinf(angle);
    w = normalize(w);
    return mat4(vec4(c * (1 - w.x * w.x) + w.x * w.x, w.x * w.y * (1 - c) + w.z * s, w.x * w.z * (1 - c) - w.y * s, 0),
                vec4(w.x * w.y * (1 - c) - w.z * s, c * (1 - w.y * w.y) + w.y * w.y, w.y * w.z * (1 - c) + w.x * s, 0),
                vec4(w.x * w.z * (1 - c) + w.y * s, w.y * w.z * (1 - c) - w.x * s, c * (1 - w.z * w.z) + w.z * w.z, 0),
                vec4(0, 0, 0, 1));
}

inline mat4 x_rotation_matrix(float angle) {
    float s = sinf(angle);
    float c = cosf(angle);
    return mat4(
            1.f, 0.f, 0.f, 0.f,
            0.f, c, s, 0.f,
            0.f, -s, c, 0.f,
            0.f, 0.f, 0.f, 1.f
    );
}

inline mat4 y_rotation_matrix(float angle) {
    float s = sinf(angle);
    float c = cosf(angle);
    return mat4(
            c, 0.f, -s, 0.f,
            0.f, 1.f, 0.f, 0.f,
            s, 0.f, c, 0.f,
            0.f, 0.f, 0.f, 1.f
    );
}

inline mat4 z_rotation_matrix(float angle) {
    float s = sinf(angle);
    float c = cosf(angle);
    return mat4(
            c, s, 0.f, 0.f,
            -s, c, 0.f, 0.f,
            0.f, 0.f, 1.f, 0.f,
            0.f, 0.f, 0.f, 1.f
    );
}

// automatic mat4 printing
//std::ostream &operator<<(std::ostream &out, const mat4 &v);

#endif //MADID_CUSTOM_MATH_H
