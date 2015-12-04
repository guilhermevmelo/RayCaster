#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Camera.h"
#include "Object.h"
#include "Light.h"
#include "Ray.h"
#include "Hit.h"

class Scene {
public:

    Camera camera;
    std::vector<Object> objects;
    std::vector<Light> lights;


    Scene(Camera &camera);
    ~Scene();

    void addLight(Light &light);
    void addObject(Object &obj);
    Hit touch(Ray &ray);
};

#endif // SCENE_H
