/*******************************************************************
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
//  FILE:        wartortle.cpp
//
//  DESCRIPTION:
//   This file implements the Wartortle class, created from
//   the base Pokemon class. It includes a constructor, 
//   destructor, and the printData function which is overwritten
//   for this class.
//
*******************************************************************/

#include "wartortle.h"
#include <iostream>

Wartortle::Wartortle() : Pokemon("Water", 49.6) {
    std::cout << "Wartortle Constructor" << std::endl;
}

Wartortle::~Wartortle() {
    std::cout << "Wartortle Destructor" << std::endl;
}

void Wartortle::printData() {
    std::cout << "Name: Wartortle, Type: " << type << ", Weight: " << weight << " lbs" << std::endl;
}
