//
//  main.cpp
//  DiceRoller
//
//  Created by Nathan Johnson on 3/28/13.
//  Copyright (c) 2013 chilledwort software All rights reserved.
//

#include "DieRoller.h"


using namespace std;


int main(int argc, char *argv[])
{    
    DieRoller roller1 = DieRoller();
    roller1.run();
    roller1.print_rollup();    
    return 0;
}

