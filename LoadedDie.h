//
//  LoadedDie.h
//  DiceRoller
//
//  Created by Nathan Johnson on 3/28/13.
//  Copyright (c) 2013 chilledwort software All rights reserved.
//

#ifndef LOADEDDIE_H
#define LOADEDDIE_H

#include "Die.h"
#include <vector>

class LoadedDie : public Die {
    
public:
    
    LoadedDie(int sides, int loaded_side, int loaded_amount);
    LoadedDie(std::string name, int sides, int loaded_side, int loaded_amount);
    void roll();

private:
    const int loaded_side_;
    const int loaded_amount_;
    std::vector<int> prob_lookup;

};


#endif
