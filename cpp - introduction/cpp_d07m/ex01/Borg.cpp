/*
** Borg.cpp for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d07m/ex01
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 10 13:33:39 2017 Forteville Gabriel
** Last update Tue Jan 10 14:51:59 2017 Forteville Gabriel
*/

#include <iostream>
#include "Borg.hh"

Borg::Ship::Ship()
{
    this->_side = 300;
    this->_maxWarp = 9;

    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl << "Your biological characteristics and technologies will be assimilated." << std::endl << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{

}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
}

void Borg::Ship::checkCore()
{
    if (this->_core->checkReactor()->isStable())
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent." << std::endl;
}
