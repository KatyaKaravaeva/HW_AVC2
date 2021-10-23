//
// Created by kikin on 21.10.2021.
//
#include "animal.h"
#include "beast.h"
#include "bird.h"
#include "fish.h"

//------------------------------------------------------------------------------
// Entering language parameters from a file.
Animal *Animal::StaticIn(FILE *file) {
    Animal *sp = NULL;
    int kind = Includes::readDigit(file);
    switch (kind) {
        case 0:
            sp = new Fish;
            sp->In(file);
            break;
        case 1:
            sp = new Beast;
            sp->In(file);
            break;
        default:
            sp = new Bird;
            sp->In(file);
            break;
    }

    return sp;
}

Animal *Animal::StaticInRnd() {
    Animal *animal = NULL;
    int kind = Includes::rndInt(1, 3);
    if (kind != 1) {
        if (kind == 2) {
            animal = new Beast;
            animal->InRnd();
        } else {
            animal = new Fish;
            animal->InRnd();
        }
    } else {
        animal = new Bird;
        animal->InRnd();
    }
    return animal;
}

#include "animal.h"
