#ifndef OBJECT_H
#define OBJECT_H


class Object {
public:
    std:vector<Face> faces;
    Object();

    Hit hit();
};

#endif // OBJECT_H
