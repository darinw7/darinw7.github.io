/*******************************************************
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
//  FILE:        pokemon.h
//
//  DESCRIPTION:
//   This header file defines the abstract class
//   'pokemon' that is being inherited by the child
//   classes. It includes the member variables type
//   and weight, which all of the pokemon have, along
//   with the constructor and virtual destructor, and
//   the printData function which the child classes
//   override and provide their own implementation of.
//
*******************************************************/

#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon {
protected:
    std::string type;
    float weight;

public:
    Pokemon(std::string t, float w);

    virtual ~Pokemon();

    virtual void printData() = 0;
};

#endif
