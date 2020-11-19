//
// PowerFist.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d10/ex01
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Fri Jan 13 15:02:00 2017 Gabriel Forteville
// Last update Fri Jan 13 16:10:18 2017 Gabriel Forteville
//


#include <iostream>
#include "PowerFist.hh"

PowerFist::PowerFist(): AWeapon("Power Fist", 8, 50)
{
  _sound = "* pschhh... SBAM! *";
}

PowerFist::~PowerFist()
{
}

void PowerFist::attack() const
{
  std::cout << _sound << std::endl;
}
