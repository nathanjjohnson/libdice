//
//  Dice.cpp
//  DiceRoller
//
//  Created by Nathan Johnson on 3/28/13.
//  Copyright (c) 2013 chilledwort software All rights reserved.
//

#include <iostream>
#include "Dice.h"


Dice::Dice() 
{
    die1 = new Die();
    die2 = new Die();
} 

Dice::Dice(Die* d1, Die* d2)
{
    die1 = d1;
    die2 = d2;
}

std::pair<int,int> Dice::roll()
{
    die1->roll();
    die2->roll();
    
    return std::make_pair(die1->get_value(), die2->get_value());
}

void Dice::printResults()
{
    std::cout << ": Die1 rolled a " << die1->get_value() 
              << ", Die2 rolled a " << die2->get_value() << "\n";
}

Dice::~Dice() 
{
    delete die1;
    delete die2;
}