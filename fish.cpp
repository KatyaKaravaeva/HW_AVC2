//
// Created by kikin on 22.10.2021.
//

#include "fish.h"
void Fish::In(FILE *file) {
    name = Includes::readStr(file);
    weight = Includes::readDigit(file);
    int kind = Includes::readDigit(file);
    switch (kind) {
        case 1:
            type = RIVER;
            break;
        case 2:
            type = SEA;
            break;
        default:
            type = LAKE;
            break;
    }
}

void Fish::InRnd() {
    name = Includes::rndStr(10);
    weight = Includes::rndInt(1, 100);
    int kind = Includes::rndInt(1, 2);

    if (kind == 1) {
        type = RIVER;
    } else if (kind == 2) {
        type = SEA;
    }
}

void Fish::Out(FILE *file) {
    fprintf(
            file,
            "Fish: name = %s, weight = %i, ",
            name,
            weight
    );

    if (type == RIVER) {
        fprintf(file, "type = RIVER. ");
    } else if (type == SEA) {
        fprintf(file, "type = SEA. ");
    }
    else{
        fprintf(file, "type = LAKE. ");
    }

    fprintf(file, "Quotient = %lf.\n", Quotient());
}

double Fish::Quotient() {
    int count = 0;
    int len = strlen(name);
    for (int i = 0; i < len; ++i) {
        count += name[i];
    }
    return static_cast<double>(count) / static_cast<double>(weight);
}