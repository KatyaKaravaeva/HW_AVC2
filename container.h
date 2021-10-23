//
// Created by kikin on 22.10.2021.
//

#ifndef HOMEWORK2AVC_CONTAINER_H
#define HOMEWORK2AVC_CONTAINER_H

#include "animal.h"

//------------------------------------------------------------------------------
class Container {
public:
    int len;

    Container();

    ~Container();

    // Entering the container contents from the specified stream.
    void In(FILE *file);

    // Random input of the container contents.
    void InRnd(int size);

    // Output the container contents to the specified stream.
    void Out(FILE *file);

    // Sorting (Straight Merge).
    void Sort(Container *c, int l, int r);

    // Auxiliary function for sorting.
    void Merge(Container *c, int l, int m, int r);

private:
    // Cleaning.
    void Clear();
    Animal *cont[10000]{};
};

#endif //HOMEWORK2AVC_CONTAINER_H
