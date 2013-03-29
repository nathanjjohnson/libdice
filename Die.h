/**
 *  Nathan Johnson 
 *  SpectraLogic Interview 3/26/2013
 */


#ifndef DIE_H
#define DIE_H

#include <vector>

class Die {


public:
   Die();
   Die(int loaded_side, int loaded_amount);
   void initialize();
   void roll();
   int getValue();
   virtual ~Die();
   
private:
   int current_value_;
   int loaded_side_;
   int loaded_amount_;
   std::vector<int> prob_lookup;
};


#endif
