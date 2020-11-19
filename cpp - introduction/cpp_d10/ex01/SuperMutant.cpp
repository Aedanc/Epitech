//
// SuperMutant.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d10/ex01
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Fri Jan 13 22:24:06 2017 Gabriel Forteville
// Last update Fri Jan 13 23:41:07 2017 Gabriel Forteville
//

#include <iostream>
#include "SuperMutant.hh"

SuperMutant::SuperMutant(): AEnemy(170, "Super Mutant")
{
  std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant()
{
  std::cout << "Aaargh ..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
  damage = damage - 3;
  if (damage < 0)
    return ;
  _hp -= (damage);
}
