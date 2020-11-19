/*
** Federation.cpp for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d07m/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 10 11:08:48 2017 Forteville Gabriel
** Last update Tue Jan 10 14:50:35 2017 Forteville Gabriel
*/

#include <iostream>
#include "Federation.hh"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;

    std::cout << "The ship USS " << name << " has been finished. It is " << length << " m in length and " << width << " m in width." << std::endl << "It can go to Warp " << maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{

}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    std::string stability;

    if (this->_core->checkReactor()->isStable())
        stability = "stable";
    else
        stability = "unstable";
    std::cout << "USS " << this->_name <<": The core is " << stability <<" at the time." << std::endl;
}


void Federation::Starfleet::Ship::promote(Captain *captain)
{
    this->_captain = captain;
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
}


Federation::Ship::Ship(int length, int width, std::string name)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = 1;

    std::cout << "The independant ship " << name << " just finished its construction. It is " << length << " m in length and " << width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{

}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    std::string stability;

    if (this->_core->checkReactor()->isStable())
        stability = "stable";
    else
        stability = "unstable";
    std::cout << this->_name <<": The core is " << stability <<" at the time." << std::endl;
}


Federation::Starfleet::Captain::Captain(std::string name)
{
    this->_name = name;
}

Federation::Starfleet::Captain::~Captain()
{

}


 std::string Federation::Starfleet::Captain::getName()
 {
     return (this->_name);
 }

 int Federation::Starfleet::Captain::getAge()
 {
     return (this->_age);
 }

 void Federation::Starfleet::Captain::setAge(int age)
 {
     this->_age = age;
 }

 Federation::Starfleet::Ensign::Ensign(std::string name)
{
    this->_name = name;
    std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}
