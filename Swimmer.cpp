/*********************************************************
* Author: Eric Hansson
* Date: 12/29/2024
* Purpose: To give more definiton the the constructor of 
* the Swimmer object
*********************************************************/
#include "Swimmer.hpp"

using namespace std;

Swimmer::Swimmer(string name, double min, double sec, double hh){
    _name = name;
    _mm = min;
    _ss = sec;
    _hh = hh;
    _sumSeconds = 0;

    _sumSeconds += min * 60;
    _sumSeconds += sec;
    _sumSeconds += hh / 100;
}
