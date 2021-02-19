#ifndef MADID_SCENE_H
#define MADID_SCENE_H

#include <iostream>

class Scene {
public:
    Scene();
    ~Scene();

    void update(double dt);
    void render();
};

#endif
