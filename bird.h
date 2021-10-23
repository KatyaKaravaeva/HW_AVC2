//
// Created by kikin on 22.10.2021.
//

#ifndef HOMEWORK2AVC_BIRD_H
#define HOMEWORK2AVC_BIRD_H
#include "includes.h"
#include "animal.h"

class Bird : public Animal {
public:
    ~Bird() override = default;

    // Entering parameters from a file.
    void In(FILE *file) override;

    // Random parameter input.
    void InRnd() override;

    // Outputting parameters to a formatted stream.
    void Out(FILE *file) override;

    // An additional function used in sorting.
    double Quotient() override;

private:
    const char *name;
    int weight;
    bool flyOrStay;
};
#endif //HOMEWORK2AVC_BIRD_H
