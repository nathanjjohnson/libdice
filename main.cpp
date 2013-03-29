/**
 *  Nathan Johnson 
 *  SpectraLogic Interview 3/26/2013
 */


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Die.h"

using namespace std;

//variable declarations
int numRolls;
Die *die1;
Die *die2;
vector<int> die1Results;
vector<int> die2Results;

//function declarations
int read_file(string file_name);
void calculateRollup(vector<int> a);

int main(int argc, char *argv[])
{    
   read_file("/Users/nate/Development/c++/Dice/pFile.txt");
   die1->initialize();
   die2->initialize();

   //Loop over numRolls and perform the
   for(int i = 0; i<numRolls; i++)
   {
      die1->roll();
      die2->roll();
      std::cout << "Throw " << i+1 << ": Die1 rolled a " << die1->getValue() 
                                 << ", Die2 rolled a " << die2->getValue() << "\n";
      die1Results.push_back(die1->getValue());
      die2Results.push_back(die2->getValue());
   }
   std::cout << "Die1 Statistics for " << die1Results.size() << " rolls: \n";
   calculateRollup(die1Results);
   std::cout << "Die2 Statistics for " << die2Results.size() << " rolls: \n";
   calculateRollup(die2Results);   

   return 0;
}

/**
 *  Function to parse the input file and store the key/value
 */
int read_file(string file_name)
{
   vector<string> list;
   ifstream in_stream;
   string line;
    
   in_stream.open(file_name.c_str());

   while(!in_stream.eof())
   {
      in_stream >> line;
      list.push_back(line);
   }

   in_stream.close();

     //temporary storage variables
     int counter = 0;
     int loadedSide = 0;
     int loadedAmount = 0;


   //iterator over the list and split up the key value pairs to use
   for(int i = 0; i < list.size(); i++)
   {
     int positionOfEquals = list[i].find("=");
     string key = list[i].substr(0, positionOfEquals );
     string value = list[i].substr(positionOfEquals + 1);  

     if(key == "Dice") {
        counter++;
     }
     else if(key == "NumRolls") {
        numRolls = atoi(value.c_str());
     }
     else if(key == "LoadedSide") {
        loadedSide = atoi(value.c_str());
     }
     //this key indicates the end of a complete die so create
     else if(key == "LoadedAmount") {
        loadedAmount = atoi(value.c_str());
        if(counter == 1){
           die1 = new Die(loadedSide, loadedAmount);
        }
        else {
           die2 = new Die(loadedSide, loadedAmount);
        }
     }

   }
   return 0;
}

void calculateRollup(vector<int> a)
{
   int totalSide1 = 0;
   int totalSide2 = 0;
   int totalSide3 = 0;
   int totalSide4 = 0;
   int totalSide5 = 0;
   int totalSide6 = 0;
   int total = a.size();

   std::cout << total << std::endl;

   
   for(int i = 0; i < total; i++)
   {

      switch(a[i]) {
         case 1:
            totalSide1++;
            break;
         case 2:
            totalSide2++;
            break;
         case 3:
            totalSide3++;
            break;
         case 4:
            totalSide4++;
            break;
         case 5:
            totalSide5++;
            break;
         case 6:
            totalSide6++;
            break;
      }
   }
   std::cout << "Side 1: " << (totalSide1 * 100 /total)  << "%\n";
   std::cout << "Side 2: " << (totalSide2 * 100 /total)  << "%\n";
   std::cout << "Side 3: " << (totalSide3 * 100 /total)  << "%\n";
   std::cout << "Side 4: " << (totalSide4 * 100 /total)  << "%\n";
   std::cout << "Side 5: " << (totalSide5 * 100 /total)  << "%\n";
   std::cout << "Side 6: " << (totalSide6 * 100 /total)  << "%\n";



}
