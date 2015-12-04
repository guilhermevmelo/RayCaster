#include "Scene.h"
#include <limits>
#include <cstdlib>

Scene::Scene(Camera &camera) : camera(camera) {}

void Scene::addObject(Object &obj) {
    objects.push_back(obj);
}

void Scene::addLight(Light &light) {
    lights.push_back(light);
}

Hit Scene::touch(Ray &ray) {

    double t = std::numeric_limits<double>::max();
    Triangle *face = NULL;
    Material *material = NULL;



    for (Object & obj : objects) {
        for (Triangle &f : obj.faces) {
            double t_i = f.get_intersection(ray);
            if(t_i > 0 && t_i < t) {
                t = t_i;
                face = f;
                material = obj.material;
            }
        }
    }
    return Hit(t, face, material);
}
