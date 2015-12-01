#ifndef SCENE_H
#define SCENE_H

#include "Camera.h"
#include "Object.h"
#include "Ray.h"

class Scene {
public:
    Camera &camera;
    std::vector<Object *> objects;
    std::vector<Light> lights;

    Scene();
    Scene(Camera &camera);
    ~Scene();

    void addLight(Light &light);
    void addObject(Object &obj);
    void touch(Ray &ray);
};

#endif // SCENE_H
