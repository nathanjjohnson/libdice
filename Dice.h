//
//  Dice.h
//  DiceRoller
//
//  Created by Nathan Johnson on 3/28/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef DiceRoller_Dice_h
#define DiceRoller_Dice_h

#include "Die.h"

class Dice {
    
public:
   Dice();
   Dice(int,int, int, int);
   virtual ~Dice();

   //call initialize the members
   void initialize();
    
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
