/**********************************************************************
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
//  FILE:        pokemon.cpp
//
//  DESCRIPTION:
//   This file implements the constructor and destructor of the Pokemon
//   class. It initializes the type and weight, and prints out
//   "Pokemon Constructor" when a pokemon object is created. Conversely,
//   the destructor prints its message when the object is deleted.
//
**********************************************************************/

#include "pokemon.h"
#include <iostream>

Pokemon::Pokemon(std::string t, float w) : type(t) , weight(w) {
    std::cout << "Pokemon Constructor" << std::endl;
}

Pokemon::~Pokemon() {
    std::cout << "Pokemon Destructor" << std::endl;
}

