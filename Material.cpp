#include "Material.h"

Material::Material() {}

Material::Material(Color ambient, Color diffuse, Color specular, double shininess)
  : ambient(ambient), diffuse(diffuse), specular(specular), shininess(shininess){ }
