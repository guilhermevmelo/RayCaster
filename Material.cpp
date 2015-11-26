#include "Material.h"

Material::~Material() {}

Material::Material(Cor ambiente, Cor difusa, Cor especular)
  : ambiente(ambiente), difusa(difusa), especular(especular){ }
