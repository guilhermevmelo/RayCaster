#include "Scene.h"

Scene::Scene() {
    objects = new std::vector<Object *>();
}

Scene::Scene(Camera &camera) : camera(camera) {
    objects = new std::vector<Object *>();
}

void Scene::addObject(Object &obj) {
    objects.push_back(obj);
}

void Scene::addLight(Light &light) {
    lights.push_back(light);
}

void Scene::touch(Ray &ray) {

}
