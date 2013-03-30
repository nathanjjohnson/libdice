//
//  Dice.cpp
//  DiceRoller
//
//  Created by Nathan Johnson on 3/28/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Dice.h"


Dice::Dice() 
{
    die1 = new Die(0,0);
    die2 = new Die(0,0);
} 

Dice::Dice(int a, int b, int c, int d)
{
    die1 = new Die(a, b);
    die2 = new Die(c, d);
}

void Dice::initialize()
{
    die1->initialize();
    die2->initialize();
}

std::pair<int,int> Dice::roll()
{
    die1->roll();
    die2->roll();
    
    return std::make_pair(die1->getValue(), die2->getValue());
}

void Dice::printResults()
{
    std::cout << ": Die1 rolled a " << die1->getValue() 
              << ", Die2 rolled a " << die2->getValue() << "\n";
}

Dice::~Dice() 
{
    delete die1;
    delete die2;
}