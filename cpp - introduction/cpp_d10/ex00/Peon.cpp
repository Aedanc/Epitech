//
// Peon.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d10/ex00
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Fri Jan 13 13:15:54 2017 Gabriel Forteville
// Last update Fri Jan 13 14:01:59 2017 Gabriel Forteville
//

#include "Peon.hh"

Peon::Peon(std::string name): Victim(name)
{
  std::cout << "Zog zog" << std::endl;
}

Peon::~Peon()
{
  std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const
{
  std::cout << _name << "has been turned into a pink pony !" << std::endl;
}
