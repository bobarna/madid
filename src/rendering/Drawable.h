#ifndef MADID_DRAWABLE_H
#define MADID_DRAWABLE_H

#include "../utility/gl.h"

class Drawable {
protected:
    GLuint vao, vbo;

public:
    Drawable();

    virtual void Draw() = 0;

    ~Drawable();
};


#endif //MADID_DRAWABLE_H
