//
//  LoadedDie.cpp
//  DiceRoller
//
//  Created by Nathan Johnson on 3/28/13.
//

#include <iostream>
#include <time.h>
#include <cstdlib>
#include "LoadedDie.h"

/**
 *  Three Argument Constructor
 */
LoadedDie::LoadedDie(int sides, int loaded_side, int loaded_amount)
    :Die(sides),
     loaded_side_(loaded_side),
     loaded_amount_(loaded_amount),
     prob_lookup(0)
{
    //initialize the probability lookup table
    for(int i = 1; i <= sides_; i++) {
        if(i == loaded_side_ && loaded_amount_ > 0) {
            for(int j = 0; j < loaded_amount_; j++) {
                prob_lookup.push_back(i);
            }
        }
        else {
            prob_lookup.push_back(i);
        } 
    }
    
    //make sure to get a different seed every time
    srand (time(NULL));
}

/**
 *  Three Argument Constructor
 */
LoadedDie::LoadedDie(std::string name, int sides, int loaded_side, int loaded_amount)
                : Die(sides, name),
                  loaded_side_(loaded_side),
                  loaded_amount_(loaded_amount),
                  prob_lookup(0)
{
    //initialize the probability lookup table
    for(int i = 1; i <= sides_; i++) {
        if(i == loaded_side_ && loaded_amount_ > 0) {
            for(int j = 0; j < loaded_amount_; j++) {
                prob_lookup.push_back(i);
            }
        }
        else {
            prob_lookup.push_back(i);
        } 
    }
    
    //make sure to get a different seed every time
    srand (time(NULL));
}

void LoadedDie::roll()
{
    int myRand = rand() % prob_lookup.size();
    current_value_ = prob_lookup[myRand];
}
