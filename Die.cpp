/**
 *  Nathan Johnson 
 *  SpectraLogic Interview 3/26/2013
 */

#include "Die.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

/**
 *  Default Constructor
 */
Die::Die() :
           current_value_(1),
           prob_lookup(0)
{
    loaded_side_ = 0;
    loaded_amount_ = 0;
    
    srand(time(NULL));
}

/**
 *  Two Argument Constructor
 */
Die::Die(int loaded_side, int loaded_amount):
         current_value_(1),
         prob_lookup(0)
{
   loaded_side_ = loaded_side;
   loaded_amount_ = loaded_amount;
 
   //make sure to get a different seed every time
   srand (time(NULL));
}

/**
 *  This function builds a vector that holds
 *  all the possible outcomes with proper weighting
 *  for each.
 */
void Die::initialize()
{
   for(int i = 1; i <= 6; i++) {
      if(i == loaded_side_ && loaded_amount_ > 0) {
         for(int j = 0; j < loaded_amount_; j++) {
            prob_lookup.push_back(i);
         }
      }
      else {
         prob_lookup.push_back(i);
      } 
   }
}


/**
 * This function sets the current_value to a random
 * lookup in the probability table.
 */
void Die::roll() 
{
  //generate random number in lookup range 
  int myRand = rand() % prob_lookup.size();
  current_value_ = prob_lookup[myRand];
}




int Die::getValue()
{
   return current_value_;
}

/**
 * This function sets the values for the loaded
 * side and loaded amount.
 */
void Die::setLoading(int loaded_side, int loaded_amount)
{
    loaded_side_ = loaded_side;
    loaded_amount_ = loaded_amount;
    this->initialize();
}

Die::~Die()
{}


