//
// Created by kikin on 22.10.2021.
//

#ifndef HOMEWORK2AVC_BEAST_H
#define HOMEWORK2AVC_BEAST_H

#include "includes.h"
#include "animal.h"

class Beast : public Animal {
public:
    ~Beast() override = default;

    // Entering parameters from a file.
    void In(FILE *file) override;

    // Random parameter input.
    void InRnd() override;

    //Random parameter input.
    void Out(FILE *file) override;

    double Quotient() override;

private:
    const char *name;
    int weight;
    enum {
        PREDATORS,
        HERBIVORES,
        INSECTIVORES
    };
    int type;
};

#endif //HOMEWORK2AVC_BEAST_H
