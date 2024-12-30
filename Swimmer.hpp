/*******************************************************
* Author: Eric Hansson
* Date: 12/29/2024
* Purpose: Object to represent a swimmer. Their name and 
* their time.
*******************************************************/
#ifndef _SWIMMER_HPP_
#define _SWIMMER_HPP_

#include <string>

class Swimmer{
private:
    std::string _name;
    double _sumSeconds;
    double _mm, _ss, _hh;

public:
    // Default constructor
    Swimmer() : _name(""), _sumSeconds(0), _mm(0), _ss(0), _hh(0) {}

    // Constructor with parameters
    Swimmer(std::string name, double min, double sec, double hh);

    // Accessor/modifier for name
    std::string getName() const {return _name;};
    std::string getName() {return _name;};

    // Accessor/modifier for sumSeconds
    double getSumSeconds() const {return _sumSeconds;}
    double getSumSeconds() {return _sumSeconds;}

    // Accessor/modifier for sumSeconds
    double getMinutes() const {return _mm;}
    double getMinutes() {return _mm;}

    // Accessor/modifier for sumSeconds
    double getSeconds() const {return _ss;}
    double getSeconds() {return _ss;}

    // Accessor/modifier for sumSeconds
    double getHH() const {return _hh;}
    double getHH() {return _hh;}
};

#endif
