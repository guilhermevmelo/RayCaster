#include "Material.h"

Material::~Material() {}

Material::Material(Color ambient, Color diffuse, Color specular)
  : ambient(ambient), diffuse(diffuse), specular(specular){ }
