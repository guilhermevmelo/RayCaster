#include "Object.h"

Object::Object(Material material):material(material){

}

Object::Object() {}

void Object::addTriangle(Triangle t) {
    //std::cout << "DEBUG: added triangle" << std::endl;
    faces.push_back(t);
}


void Object::applyTransformation(Matrix &matrix) {
    for (Triangle &f : faces) {
        f.applyTransformation(matrix);
    }
}
