//
//  Die.h
//  DiceRoller
//
//  Created by Nathan Johnson on 3/28/13.
//  Copyright (c) 2013 chilledwort software All rights reserved.
//


#ifndef DIE_H
#define DIE_H

#include <vector>
#include <string>

class Die {


public:
    Die();
    Die(int);
    Die(int, std::string);
    
    //declare all the functions as virtual
    //so that the correct versions get called
    //in inherited versions
    virtual int get_value();
    virtual const int get_sides();
    virtual std::string get_name();
    virtual void roll();
    virtual ~Die();
   
protected:
    int current_value_;
    const int sides_;
    const std::string name_;
};


#endif
