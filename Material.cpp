#include "Material.h"

Material::~Material() {}

Material::Material(double ambient, double diffuse, double specular)
  : ambient(ambient), diffuse(diffuse), specular(specular){ }
