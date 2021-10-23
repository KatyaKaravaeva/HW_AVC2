//
// Created by kikin on 22.10.2021.
//

#ifndef HOMEWORK2AVC_FISH_H
#define HOMEWORK2AVC_FISH_H
#include "includes.h"
#include "animal.h"

class Fish : public Animal {
public:
    ~Fish() override = default;

    // Entering parameters from a file.
    void In(FILE *file) override;

    // Random parameter input.
    void InRnd() override;

    // Outputting parameters to a formatted stream.
    void Out(FILE *file) override;

    // Calculation of the perimeter of a generalized figure.
    double Quotient() override;

private:
    const char *name;
    int weight;
    enum {
        RIVER,
        SEA,
        LAKE
    };
    int type;
};
#endif //HOMEWORK2AVC_FISH_H
