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
//  FILE:        wartortle.h
//
//  DESCRIPTION:
//   This header file defines the Wartortle
//   class, which inherits from the base Pokemon
//   class. It implements the constructor,
//   destructor, as well as the printData
//   function that is just for Wartortle.
//
*****************************************************/

#ifndef WARTORTLE_H
#define WARTORTLE_H

#include "pokemon.h"

class Wartortle : public Pokemon {
public:
    Wartortle();
    ~Wartortle();
    void printData();
};

#endif
