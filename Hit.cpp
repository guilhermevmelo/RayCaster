#include "Hit.h"

Hit::Hit(double distance, Triangle *face):distance(distance) {
    face = face;
}

Color Hit::getColor() {
    return Color(100, 100, 100);
}
