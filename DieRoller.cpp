//
//  DieRoller.cpp
//  DiceRoller
//
//  Created by Nathan Johnson on 3/28/13.
//  Copyright (c) 2013 chilledwort software All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iterator>
#include "DieRoller.h"
#include "LoadedDie.h"

using namespace std;

int DieRoller::run()
{
    //read the config file
    read_file("/Users/nate/Development/c++/DiceRoller/pFile.txt");

        
    //loop over the dice
    for (vector<Die*>::iterator current_die = my_dice_.begin();
         current_die!=my_dice_.end(); ++current_die) {

        //temporary vector to store the rolling results
        vector<int> tmpvec; 

        //loop to perform every roll and push the results
        //into tmpvec
        for(int i = 0; i < num_rolls_; i++)
        {
           (*current_die)->roll();
           tmpvec.push_back((*current_die)->get_value());
        }
        
        //insert the pair of the current die and the vector of results
        //into the map of die history
        die_history_map_.insert(std::make_pair<Die*, 
                                vector<int> >(*current_die, tmpvec));        
    }
    
    //TODO Add error checking and return proper status
    return 0;
}

/**
 *  Function to parse the input file and store the key/value
 */
void DieRoller::read_file(string file_name)
{
    vector<string> list;
    ifstream in_stream;
    string line;
    
    in_stream.open(file_name.c_str());
    
    while(in_stream >> line)
    {
        std::cout << line << "\n"; 
        list.push_back(line);
    }
    
    in_stream.close();
    
    
    
    //temporary storage variables
    int sides = 0;
    int loaded_side = 0;
    int loaded_amount = 0;
    std::string name = "";
    std::string type = "";
    std::string key;
    std::string value;
    
    //iterator over the list and split up the key value pairs to use
    for(int i = 0; i < list.size(); i++)
    {
        //parse the key/value pair
        int positionOfEquals = list[i].find("=");
        key = list[i].substr(0, positionOfEquals );
        value = list[i].substr(positionOfEquals + 1);  
                
        if(key == "NumRolls") 
        {
            //set the class member variable
            num_rolls_ = atoi(value.c_str());
        }
        if(key == "Dice") {
            name = value;
        }
        if(key == "Type")
        {
            type = value;
        }
        if(key == "Sides" && type == "Normal") {
            sides = atoi(value.c_str());
            my_dice_.push_back(new Die(sides, name));
        }
        if(key == "Sides" && type != "Normal") {
            sides = atoi(value.c_str());
        }
        if(key == "LoadedSide") {
              loaded_side = atoi(value.c_str());
        }
        //this key is currently serving as the trigger to create
        //a new Die... this should detect different die types and
        //use a factory method to create the proper one
        if(key == "LoadedAmount") {
            loaded_amount = atoi(value.c_str());
            my_dice_.push_back(new LoadedDie(name, sides, loaded_side, loaded_amount));
        }
    }
}

void DieRoller::print_rollup()
{
    //iterator over map of history
    //count every results
    for(map<Die*,vector<int> >::iterator current_die_history = 
                    die_history_map_.begin();
        current_die_history!=die_history_map_.end(); ++current_die_history) {
        
        Die* current_die = current_die_history->first;
        vector<int> current_history = current_die_history->second;
        
        int sides = current_die_history->first->get_sides();
        cout << "this die has " << sides << " sides" <<endl;
        
        //creates a vector of ints and initializes it with sides
        //elements each set to 0.
        vector<int> side_tracker(sides,0);

        //iterator over the history
        //side_tracker is a vector initalized to the number of sides
        //this loop will increment the vector position of the side rolled
        for(int i = 0; i < num_rolls_; i++)
        {
            side_tracker[current_history[i]-1]++;
        }
        
        //iterate over the side_tracker vector and print the results of
        //the counting
        std::cout << current_die->get_name() << " Summary: \n";
        for(int j = 0; j < sides; j++)
        {
            std::cout << "\tSide " << j + 1 << " : " << (side_tracker[j] * 100 /num_rolls_)  << "%\n";
        }
        
    }
                    
}
