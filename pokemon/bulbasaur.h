/****************************************************
//
//  NAME:        Darin Wong
//
//  HOMEWORK:    9
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        December 9, 2024
//
//  FILE:        bulbasaur.h
//
//  DESCRIPTION:
//   This header file defines the Bulbasaur
//   class, which inherits from the base Pokemon
//   class. It implements the constructor,
//   destructor, as well as the printData
//   function that is just for Bulbasaur.
//
****************************************************/

#ifndef BULBASAUR_H
#define BULBASAUR_H

#include "pokemon.h"

class Bulbasaur : public Pokemon {
public:
    Bulbasaur();
    ~Bulbasaur();
    void printData();
};

#endif

