//
// Created by kikin on 22.10.2021.
//

#include "beast.h"

void Beast::In(FILE *file) {
    name = Includes::readStr(file);
    weight = Includes::readDigit(file);
    int kind = Includes::readDigit(file);
    switch (kind) {
        case 0:
            type = PREDATORS;
            break;
        case 1:
            type = HERBIVORES;
            break;
        case 2:
            type = INSECTIVORES;
            break;
        default:
            type = PREDATORS;
            break;
    }
}

void Beast::InRnd() {
    name = Includes::rndStr(10);
    weight = Includes::rndInt(1, 100);
    int kind = Includes::rndInt(0, 2);
    if (kind == 0) {
        type = PREDATORS;
    } else if (kind == 1) {
        type = HERBIVORES;
    } else if (kind == 2) {
        type = INSECTIVORES;
    }
}

void Beast::Out(FILE *file) {
    fprintf(
            file,
            "Beast: name = %s, weight = %i, ",
            name,
            weight
    );

    if (type == PREDATORS) {
        fprintf(file, "type = PREDATORS. ");
    } else if (type == HERBIVORES) {
        fprintf(file, "type = HERBIVORES. ");
    } else if (type == INSECTIVORES) {
        fprintf(file, "type = INSECTIVORES. ");
    }

    fprintf(file, "Quotient = %lf.\n", Quotient());
}

double Beast::Quotient() {
    int count = 0;
    int len = strlen(name);
    for (int i = 0; i < len; ++i) {
        count += name[i];
    }
    return static_cast<double>(count) / static_cast<double>(weight);
}