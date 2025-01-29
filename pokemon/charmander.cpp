/******************************************************************
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
//  FILE:        charmander.cpp
//
//  DESCRIPTION:
//   This file implements the Charmander class, created from
//   the base Pokemon class. It includes a constructor, 
//   destructor, and the printData function which is overwritten
//   for this class.
******************************************************************/

#include "charmander.h"
#include <iostream>

Charmander::Charmander() : Pokemon("Fire", 18.7) {
    std::cout << "Charmander Constructor" << std::endl;
}

Charmander::~Charmander() {
    std::cout << "Charmander Destructor" << std::endl;
}

void Charmander::printData() {
    std::cout << "Name: Charmander, Type: " << type << ", Weight: " << weight << " lbs" << std::endl;
}

