//
//  DieRoller.h
//  DiceRoller
//
//  Created by Nathan Johnson on 3/28/13.
//  Copyright (c) 2013 chilledwort software All rights reserved.
//

#ifndef DIEROLLER_H
#define DIEROLLER_H

#include "Die.h"
#include <map>

class DieRoller {
  
public:
    //function declarations
    void read_file(std::string file_name);
    
    //function to run the simulation on all the dice
    int run();
    
    //function to print the statistical results of the dice rolling
    void print_rollup();
    
private:
    //variable declarations
    int num_rolls_;
        
    //map keyed by pointer to Die that holds vector of roll history
    std::map<Die*, std::vector<int> > die_history_map_;
    
    //vector to store the dice
    std::vector<Die*> my_dice_;
    
};

#endif
