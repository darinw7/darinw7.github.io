/***********************************************
//
//  NAME:       Darin Wong
//
//  HOMEWORK:   9
//
//  CLASS:      ICS 212
//
//  INSTRUCTOR: Ravi Narayan
//
//  DATE:       December 9, 2024
//
//  FILE:       charmander.h
//
//  DESCRIPTION:
//   This header file defines the Charmander
//   class, which inherits from the base Pokemon
//   class. It implements the constructor,
//   destructor, as well as the printData
//   function that is just for Charmander.
//
***********************************************/

#ifndef CHARMANDER_H
#define CHARMANDER_H

#include "pokemon.h"

class Charmander : public Pokemon {
public:
    Charmander();
    ~Charmander();
    void printData();
};

#endif

