/**************************************************************
* Author: Eric Hansson
* Date: 12/29/2024
* Purpose; Calculate the total relay time of swimmer by input 
* from a file.
* ************************************************************/
#include <ctime>
#include <iostream>
#include "Swimmer.hpp"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){ 
    //
    ifstream inFile(argv[1]);

    if(!inFile){
        cerr << "ERROR! COULD NOT OPEN FILE" << endl;
    }

    string input;
   
    // List of the swimmers
    vector<Swimmer> relay;
   
    // Store data for each swimmer
    vector<string> data;

    // Reads in data until there is nothing more to be read
    while (inFile >> input) {
        data.push_back(input);

        // When all the data for swimmer in, grab it
        if (data.size() == 3) {
            string time = data[2];
            int mm = 0;
            int ss = 0;
            int hh = 0;

            // Goes through the data, and separate the min, sec, and hh
            for(int i=0; i < time.size(); i++){
                if (time[i] == ':') {
                    mm += stoi(time.substr(0,i));
                    time.erase(0,i+1);
                }
                else if (time[i] == '.') {
                    ss += stoi(time.substr(0,i));
                    hh += stoi(time.substr(i+1, time.back()));
                    time.clear();
                }
            }

            // When all data is collected, construct Swimmer object
            Swimmer sw(data[0]+" "+data[1], mm, ss, hh);

            // Add swimmer to the list
            relay.push_back(sw);
           
            // Clear the data list and time
            data.clear();
            time.clear();
        }
        
    }

    // Closes file when reading data is done
    inFile.close();


    double totaltMin = 0;
    double totalSec = 0;
    double totalHH = 0;
    
    // Gets all the time data from each swimmer, sums them per min, sec, and hh
    for(auto i : relay){
        totaltMin += i.getMinutes();
        totalSec += i.getSeconds();
        totalHH += i.getHH();
    }

    // if total seconds are more than 60
    if(totalSec >= 60){
        // turn 60 seconds to 1 min and add to minutes variable
        int extraMin = (totalSec/60);
        totaltMin += extraMin;
        totalSec -= (extraMin*60);
    }

    // if total of hh is more than 100 
    if(totalHH >= 100){
        // turn .100 to 1 second and adds it to the total of seconds variable
        int extraSec = (totalHH/100);
        totalSec += extraSec;
        totalHH -=  (extraSec*100);
    }

    // Prints out the totalt relay time
    cout << "Relay time from file input" << endl;
    cout << "===============================" << endl;

    cout << totaltMin << ":" << totalSec << "." << totalHH << endl;

    

    return 0;
}
