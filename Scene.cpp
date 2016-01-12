#include "Scene.h"
#include <limits>
#include <cstdlib>

Scene::Scene(Camera &camera, Color background) : camera(camera), background(background) {}

void Scene::addObject(Object &obj) {
    objects.push_back(obj);
}

void Scene::addLight(Light &light) {
    lights.push_back(light);
}

Color Scene::touch(Ray &ray) {
    //std::cout << "Scene::touch()" << std::endl;
    double t = std::numeric_limits<double>::max();
    Triangle *face = NULL;
    Material *material = NULL;
    bool did_hit = false;
    int num_hits = 0;
    Color colour;

    //std::cout << "DEBUG: entering objects list loop" << std::endl;

    for (Object &obj : objects) {
        //std::cout << "\n:OBJECT:" << std::endl;
        for (Triangle &f : obj.faces) {
            //std::cout << ":FACE: t before iteration = " << t << std::endl;

            Hit hit = f.get_intersection(ray);

//            if (hit == NULL)
//                colour = Color(0, 0, 0);

//            //std::cout << ":::: t_i = " << t_i << std::endl;

            if(hit.distance > 0 && hit.distance < t) {
                t = hit.distance;
                face = hit.face;
                material = &obj.material;
                did_hit = true;
                num_hits++;
            }
        }
        //std::cout << "\n EXITED OBJECT with face = " << face << " and material = " << material << std::endl;
    }

    //std::cout << "DEBUG: leaving object list loop" << std::endl;

    if (!did_hit)
        return background;

    return process_lights(*material);
}

Color Scene::process_lights(Material &material) {
    Color c;
    for (Light &l : lights) {
        c = l * material;
    }

    return c;
}
