/*************************************************************
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
//  FILE:        main.cpp
//
//  DESCRIPTION:
//   This file implements the main function, which works
//   through using the Pokemon class and its child classes
//   to use polymorphism. It implements dynamic memory
//   allocation to create the Pokemon objects, polymorphism,
//   and containers like map and vector to go through the
//   pokedex.
//
*************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include "bulbasaur.h"
#include "charmander.h"
#include "wartortle.h"

/****************************************************
// 
//  Function name: checkPokedex
//
//  DESCRIPTION:   This function passes a pokemon
//                 pointer to call the polymorphic
//                 printData function to print
//                 information of a pokemon.
//
//  Paramaters:    pokemon(pokemon*): Pointer to a
//                 pokemon object
//
//  Return values: None
//
*****************************************************/
void checkPokedex(Pokemon *pokemon) {
    
    pokemon->printData();
}

/******************************************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   This function creates instances of three different pokemon objects,
//                 gives them nicknames, and then puts them into a map as keys.
//
//  Parameters:    argc(int): number of arguments passed to program
//                 argv(char*[]): array of arguments passed to program
//
//
//  Return values: 0: program runs successfully
//
//
******************************************************************************************/

int main() {
    Pokemon* bulbasaur = new Bulbasaur();
    Pokemon* charmander = new Charmander();
    Pokemon* wartortle = new Wartortle();

    std::vector<std::string> nicknames;
    nicknames.push_back("Ivy");
    nicknames.push_back("Sriracha");
    nicknames.push_back("Aquamarine");

    std::map<std::string, Pokemon*> pokedex;
    pokedex["Ivy"] = bulbasaur;
    pokedex["Sriracha"] = charmander;
    pokedex["Aquamarine"] = wartortle;

    for(size_t i = 0; i < nicknames.size() ; ++i) {
        const std::string& nickname = nicknames[i];
        std::cout << std::endl << "Using Nickname(key): " << nickname << std::endl; 
        std::cout << "Accessing the address of the corresponding Pokemon Object: " << std::endl;
        checkPokedex(pokedex[nickname]);
    }

    delete bulbasaur;
    delete charmander;
    delete wartortle;

    return 0;
}

