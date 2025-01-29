/**************************************************************
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
//  FILE:        bulbasaur.cpp
//
//  DESCRIPTION:
//   This file implements the Bulbasaur class, created from
//   the base Pokemon class. It includes a constructor, 
//   destructor, and the printData function which is overwritten
//   for this class.
//
**************************************************************/

#include "bulbasaur.h"
#include <iostream>

Bulbasaur::Bulbasaur() : Pokemon("Grass/Poison", 15.2) {
    std::cout << "Bulbasaur Constructor" << std::endl;
}

Bulbasaur::~Bulbasaur() {
    std::cout << std::endl << "Bulbasaur Destructor" << std::endl;
}

void Bulbasaur::printData() {
    std::cout << "Name: Bulbasaur, Type: " << type << ", Weight: " << weight << " lbs" << std::endl;
}

