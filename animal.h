//
// Created by kikin on 21.10.2021.
//

#ifndef HOMEWORK2AVC_ANIMAL_H
#define HOMEWORK2AVC_ANIMAL_H
#include <cstdio>
#include "animal.h"
#include "includes.h"

//------------------------------------------------------------------------------
// Class that summarizes all available languages.
class Animal {
public:
    virtual ~Animal() = default;

    // Entering a generalized language.
    static Animal *StaticIn(FILE *file);

    // Entering a generalized language.
    virtual void In(FILE *file) = 0;

    // Random input of a generalized language.
    static Animal *StaticInRnd();

    // Virtual method of random language input.
    virtual void InRnd() = 0;

    // The derivation of a generalized figure.
    virtual void Out(FILE *file) = 0;

    // Calculation of the perimeter of a generalized figure.
    virtual double Quotient() = 0;
};
#endif //HOMEWORK2AVC_ANIMAL_H
