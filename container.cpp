//
// Created by kikin on 22.10.2021.
//

#include <cstdio>
#include "container.h"

//------------------------------------------------------------------------------
// Container builder.
Container::Container() : len{0} {}

//------------------------------------------------------------------------------
// Container destructor.
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Freeing memory.
void Container::Clear() {
    delete[] *cont;
    len = 0;
}

//------------------------------------------------------------------------------
// Input of the container contents.
void Container::In(FILE *file) {
    while (!feof(file)) {
        if ((cont[len] = Animal::StaticIn(file)) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Random input of the container contents.
void Container::InRnd(int size) {
    while (len < size) {
        if ((cont[len] = Animal::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Output the container contents to the specified stream.
void Container::Out(FILE *file) {
    fprintf(file, "Container contains %d elements.\n", len);

    for (int i = 0; i < len; i++) {
        fprintf(file, "%d: ", i + 1);
        cont[i]->Out(file);
    }
}

//------------------------------------------------------------------------------
// Sorting (Straight Merge).
void Container::Sort(Container *c, int l, int r) {
    {
        if (l < r) {
            int m = l + (r - l) / 2;
            Sort(c, l, m);
            Sort(c, m + 1, r);
            Merge(c, l, m, r);
        }
    }
}

//------------------------------------------------------------------------------
// Auxiliary function for sorting.
void Container::Merge(Container *c, int l, int m, int r) {
    {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;
        Container *L = new Container[n1];
        Container *R = new Container[n2];
        for (i = 0; i < n1; i++)
            L->cont[i] = (c->cont[l + i]);
        for (j = 0; j < n2; j++)
            R->cont[j] = (c->cont[m + 1 + j]);

        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2) {
            if (L->cont[i]->Quotient() >= R->cont[j]->Quotient()) {
                c->cont[k] = (L->cont[i]);
                i++;
            } else {
                c->cont[k] = R->cont[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            c->cont[k] = (L->cont[i]);
            i++;
            k++;
        }
        while (j < n2) {
            c->cont[k] = R->cont[j];
            j++;
            k++;
        }
    }
}
