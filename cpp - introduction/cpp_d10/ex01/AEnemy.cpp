//
// AEnemy.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d10/ex01
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Fri Jan 13 16:25:28 2017 Gabriel Forteville
// Last update Fri Jan 13 22:06:02 2017 Gabriel Forteville
//

#include <iostream>
#include "AEnemy.hh"

AEnemy::AEnemy(int hp, std::string const& type):
  _hp(hp),
  _type(type)
{}

AEnemy::~AEnemy() {};

std::string const AEnemy::getType() const {return _type;}
int AEnemy::getHP() const {return _hp;}

void AEnemy::takeDamage(int damage)
{
  if (damage < 0)
    return ;
  _hp -= damage;
}
