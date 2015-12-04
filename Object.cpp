#include "Object.h"

Object::Object(Material material):material(material){

}

void Object::addTriangle(Triangle t) {
    faces.push_back(t);
}
