//
//  Die.cpp
//  DiceRoller
//
//  Created by Nathan Johnson on 3/28/13.
//  Copyright (c) 2013 chilledwort software All rights reserved.
//

#include "Die.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

/**
 *  Default constructor 
 *  Builds a 6-sided die
 */
Die::Die() :
sides_(6)
{
    current_value_ = 1;
    srand(time(NULL));
}

/**
 *  Overloade Constructor
 *  Builds an n-sided die
 */
Die::Die(int n) :
           sides_(n)
{
    current_value_ = 1;
    srand(time(NULL));
}

Die::Die(int n, std::string name) :
                             sides_(n),
                             name_(name)
{
    current_value_ = 1;
    srand(time(NULL));
}

/**
 * This function sets the current_value to a random
 * lookup in the probability table.
 */
void Die::roll() 
{
  //generate random number in lookup range 
  current_value_ = rand() % sides_ + 1;
}

/**
 * Return the current value of the die.
 */
int Die::get_value()
{
   return current_value_;
}

const int Die::get_sides()
{
    return sides_;    
}

string Die::get_name()
{
    return name_;
}
/**
 * Destructor
 */
Die::~Die()
{}


