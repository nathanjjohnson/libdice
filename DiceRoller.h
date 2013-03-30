//
//  DiceRoller.h
//  DiceRoller
//
//  Created by Nathan Johnson on 3/28/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef DiceRoller_DiceRoller_h
#define DiceRoller_DiceRoller_h

#include <string>
#include <vector>
#include "Dice.h"

class DiceRoller {
    
public:
   //function declarations
   int read_file(std::string file_name);
   int run();
   void printRollup();

private:
   //variable declarations
   int numRolls;
    std::vector<std::pair<int,int> > diceHistory;
    
   Dice *dice1;
};

#endif
