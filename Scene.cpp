#include "Scene.h"
#include <limits>
#include <cstdlib>

Scene::Scene(Camera &camera, Color background) : camera(camera), background(background) {
    //WtoC = Matrix::world_camera(camera);
    //CtoW = Matrix::camera_world(camera);
}

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

    //std::cout << "DEBUG: entering objects list loop" << std::endl;

    for (Object &obj : objects) {
        //std::cout << "\n:OBJECT:" << std::endl;
        for (Triangle &f : obj.faces) {
            //std::cout << ":FACE: t before iteration = " << t << std::endl;

            Hit hit = f.get_intersection(ray);

            if(hit.distance > 0 && hit.distance < t && hit.face != NULL) {
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

    return process_lights(*material, ray.origin + t * ray.vector, face->normal);
}

Color Scene::process_lights(Material &material, Point intersection, Vector n) {
    Color c (1, 1, 1);

    for (Light &light : lights) {
        //c = light * material;
        Vector l = (light.position - intersection).normalize();
        Vector v = (camera.origin - intersection).normalize();
        Vector r = (2 * (l * n))*n - l;

        Color Ia(light.color.r * material.ambient.r,
                 light.color.g * material.ambient.g,
                 light.color.b * material.ambient.b);

        Color Id = Color(light.color.r * material.diffuse.r,
                         light.color.g * material.diffuse.g,
                         light.color.b * material.diffuse.b) * (n*l);

        Color Is = Color(light.color.r * material.specular.r,
                         light.color.g * material.specular.g,
                         light.color.b * material.specular.b) * pow(r*v, material.shininess);

        c = c * (Ia + Id + Is);
    }
    return c;
}
