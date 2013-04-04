//
//  Dice.h
//  DiceRoller
//
//  Created by Nathan Johnson on 3/28/13.
//  Copyright (c) 2013 chilledwort software All rights reserved.
//

#ifndef DICE_H
#define DICE_H

#include "Die.h"

class Dice {
    
public:
   Dice();
   Dice(Die*, Die*);
   virtual ~Dice();

   //roll the dice and return a pair of values
   std::pair<int,int> roll();
    
   //print the current results 
   void printResults();

private:
   //Member variables to hold
   Die* die1;
   Die* die2;
    
};

#endif
