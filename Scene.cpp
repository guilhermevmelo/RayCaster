#include "Scene.h"

Scene::Scene(Camera &camera) : camera(camera) {}

void Scene::addObject(Object &obj) {
    objects.push_back(obj);
}

void Scene::addLight(Light &light) {
    lights.push_back(light);
}

void Scene::touch(Ray &ray) {

}
