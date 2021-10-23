//
// Created by kikin on 22.10.2021.
//

#include "bird.h"

void Bird::In(FILE *file) {
    name = Includes::readStr(file);
    weight = Includes::readDigit(file);
    flyOrStay = Includes::readDigit(file) == 0;
}

void Bird::InRnd() {
    name = Includes::rndStr(10);
    weight = Includes::rndInt(1, 100);
    flyOrStay = Includes::rndInt(0, 2) == 0;
}

void Bird::Out(FILE *file) {
    fprintf(
            file,
            "Bird: name = %s, weight = %i, flyOrStay = %s, ",
            name, weight, flyOrStay ? "TRUE " : "FALSE "
    );

    fprintf(file, "Quotient = %lf.\n", Quotient());
}

double Bird::Quotient() {
    int count = 0;
    int len = strlen(name);
    for (int i = 0; i < len; ++i) {
        count += name[i];
    }
    return static_cast<double>(count) / static_cast<double>(weight);
}
