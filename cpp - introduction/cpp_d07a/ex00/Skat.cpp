/*
** Skat.cpp for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d07a/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 10 17:47:25 2017 Forteville Gabriel
** Last update Wed Jan 11 09:31:58 2017 Forteville Gabriel
*/


#include <iostream>
#include "Skat.h"

Skat::Skat(std::string const& name = "bob", int stimPaks = 15)
 {
    this->_name = name;
    this->_stimPaks = stimPaks;
 }

void Skat::useStimPaks()
{
    if (this->_stimPaks != 0)
        {
            std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
            this->_stimPaks -= 1;
        }
    else
        {
            std::cout << "Mediiiiiic" << std::endl;
        }
}

void Skat::status()
{
    std::cout << "Soldier " << this->_name << " reporting " << this->_stimPaks <<" stimpaks remaining sir !" << std::endl;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something ?" << std::endl;
    this->_stimPaks += number;
}

const std::string& Skat::name()
{
    return this->_name;
}


Skat::~Skat()
{

}
