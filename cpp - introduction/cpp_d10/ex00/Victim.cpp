//
// Victime.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d10/ex00
//
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
//
// tarted on  Fri Jan 13 10:48:40 2017 Gabriel Forteville
// Last update Fri Jan 13 14:07:52 2017 Gabriel Forteville
//

#include <iostream>
#include "Victim.hh"

Victim::Victim(std::string name):
  _name(name)
{
    std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::Victim(Victim const& other):
  _name(other._name)
{
    std::cout << "Some random victim called " << other._name << " just popped !" << std::endl;
}

Victim::~Victim() {
    std::cout << "Victim " << _name << " just died for no apparent reason !" << std::endl;
}

void Victim::getPolymorphed() const
{
    std::cout << _name << " has been turned into a cute little sheep !" << std::endl;
}

std::string Victim::getName() const { return _name; }

std::ostream& operator<<(std::ostream& os, Victim const& victime)
{
  os << "I'am " << victime.getName() << " and i like otters !" << std::endl;
    return os;
}
