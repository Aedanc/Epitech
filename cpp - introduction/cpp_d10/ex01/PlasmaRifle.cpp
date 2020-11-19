//
// PlasmaRifle.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d10/ex01
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Fri Jan 13 15:02:00 2017 Gabriel Forteville
// Last update Fri Jan 13 16:06:22 2017 Gabriel Forteville
//


#include <iostream>
#include "PlasmaRifle.hh"

PlasmaRifle::PlasmaRifle(): AWeapon("Plasma Rifle", 5, 21)
{
  _sound = "* piouuu piouuu piouuu *";
}

PlasmaRifle::~PlasmaRifle()
{
}

void PlasmaRifle::attack() const
{
  std::cout << _sound << std::endl;
}
