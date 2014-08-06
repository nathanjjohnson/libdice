//
//  DiceRoller.cpp
//  DiceRoller
//
//  Created by Nathan Johnson on 3/28/13.
//  Copyright (c) 2013 chilledwort software All rights reserved.
//

#include <fstream>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include "DiceRoller.h"

using namespace std;

int DiceRoller::run()
{
    dice1 = read_file("/Users/nate/Development/c++/Dice/pFile.txt");
    //dice1->initialize();
    
    //Loop over numRolls and perform the calculations
    //store and print the results for each roll
    for(int i = 0; i<numRolls; i++)
    {
        diceHistory.push_back(dice1->roll());
        dice1->printResults();
    }

    return 0;
}

/**
 *  Function to parse the input file and store the key/value
 */
Dice* DiceRoller::read_file(string file_name)
{
    Dice *dice_set;
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
    int loadedSide2 = 0;
    int loadedAmount2 = 0;
    
    
    //iterator over the list and split up the key value pairs to use
    for(int i = 0; i < list.size(); i++)
    {
        int positionOfEquals = list[i].find("=");
        string key = list[i].substr(0, positionOfEquals );
        string value = list[i].substr(positionOfEquals + 1);  
        
        if(key == "NumRolls") 
        {
            numRolls = atoi(value.c_str());
        }
        else if(key == "Dice") {
            counter++;
        }
        else if(key == "LoadedSide" && counter == 1) {
            loadedSide = atoi(value.c_str());
        }
        else if(key == "LoadedSide" && counter == 2) {
            loadedSide2 = atoi(value.c_str());
        }
        //this key indicates the end of a complete die so create
        else if(key == "LoadedAmount" && counter == 1) {
            loadedAmount2 = atoi(value.c_str());
        }
        else if(key == "LoadedAmount" && counter == 2) {
            dice_set = new Dice();
        }
    }
    return dice_set;
}

void DiceRoller::printRollup()
{
    //record keeping variables to count the number of times
    //each side was rolled.
    int totala1=0, totala2=0, totala3=0, totala4=0, totala5=0, totala6=0;
    int totalb1=0, totalb2=0, totalb3=0, totalb4=0, totalb5=0, totalb6=0;
    
    //iterator for our vector of pairs
    std::vector<pair<int,int> >::iterator myIterator;
    
    int total = diceHistory.size();
    
    //iterate over the history pairs
    for( myIterator = diceHistory.begin();
           myIterator != diceHistory.end();
             myIterator++)
    {
        switch (myIterator->first)
        {
            case 1:
                totala1++;
                break;
            case 2:
                totala2++;
                break;
            case 3:
                totala3++;
                break;
            case 4:
                totala4++;
                break;
            case 5:
                totala5++;
                break;
            case 6:
                totala6++;
                break;
            default:
                break;
        }
        
        switch (myIterator->second)
        {
            case 1:
                totalb1++;
                break;
            case 2:
                totalb2++;
                break;
            case 3:
                totalb3++;
                break;
            case 4:
                totalb4++;
                break;
            case 5:
                totalb5++;
                break;
            case 6:
                totalb6++;
                break;
            default:
                break;
        }
    }
    
    std::cout << "Die 1 Statistics for " << total << " rolls.\n";
    std::cout << "\tSide 1: " << (totala1 * 100 /total)  << "%\n";
    std::cout << "\tSide 2: " << (totala2 * 100 /total)  << "%\n";
    std::cout << "\tSide 3: " << (totala3 * 100 /total)  << "%\n";
    std::cout << "\tSide 4: " << (totala4 * 100 /total)  << "%\n";
    std::cout << "\tSide 5: " << (totala5 * 100 /total)  << "%\n";
    std::cout << "\tSide 6: " << (totala6 * 100 /total)  << "%\n\n";

    std::cout << "Die 2 Statistics for " << total << " rolls.\n";
    std::cout << "\tSide 1: " << (totalb1 * 100 /total)  << "%\n";
    std::cout << "\tSide 2: " << (totalb2 * 100 /total)  << "%\n";
    std::cout << "\tSide 3: " << (totalb3 * 100 /total)  << "%\n";
    std::cout << "\tSide 4: " << (totalb4 * 100 /total)  << "%\n";
    std::cout << "\tSide 5: " << (totalb5 * 100 /total)  << "%\n";
    std::cout << "\tSide 6: " << (totalb6 * 100 /total)  << "%\n";
}
