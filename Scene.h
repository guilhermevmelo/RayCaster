#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Camera.h"
#include "Object.h"
#include "Light.h"
#include "Ray.h"
#include "Hit.h"
#include "Material.h"
#include "Matrix.h"

class Scene {
public:
    Camera camera;
    std::vector<Object> objects;
    std::vector<Light> lights;
    Color background;

    //Matrix WtoC;
    //Matrix CtoW;

    Scene(Camera &camera, Color background);

    void addLight(Light &light);
    void addObject(Object &obj);
    Color touch(Ray &ray);
    Color process_lights(Material &material);
};

#endif // SCENE_H
