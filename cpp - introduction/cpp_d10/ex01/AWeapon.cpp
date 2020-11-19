//
// AWeapon.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d10/ex01
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Fri Jan 13 14:33:42 2017 Gabriel Forteville
// Last update Fri Jan 13 14:56:15 2017 Gabriel Forteville
//

#include <iostream>
#include "AWeapon.hh"

AWeapon::AWeapon(std::string const& name, int damage, int cost):
  _name(name),
  _damage(damage),
  _cost(cost)
{

}

AWeapon::~AWeapon()
{
}

std::string const AWeapon::getName() const {return _name;}
int AWeapon::getAPCost() const {return _cost;}
int AWeapon::getDamage() const {return _damage;}
