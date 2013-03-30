/**
 *  Nathan Johnson 
 *  SpectraLogic Interview 3/26/2013
 */


#include "DiceRoller.h"


using namespace std;


int main(int argc, char *argv[])
{    
    DiceRoller roller1 = DiceRoller();
    roller1.read_file("/Users/nate/Development/c++/Dice/pFile.txt");
    roller1.run();
    roller1.printRollup();    
    
    

   return 0;
}

