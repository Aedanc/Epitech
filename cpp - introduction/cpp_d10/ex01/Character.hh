//
// Character.hh for  in /home/fortevg/rendu/piscine_cpp/cpp_d10/ex01
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Fri Jan 13 23:45:36 2017 Gabriel Forteville
// Last update Sat Jan 14 00:35:38 2017 Gabriel Forteville
//

#ifndef __CHARACTERE_HH_
#define __CHARACTERE_HH_

#include <iostream>
#include "AWeapon.hh"

class Character
{
private:
  std::string _name;
  int _ap;
  AWeapon *_weapon;

public:
  Character(std::string const & name);
  ~Character();
  void recoverAP();
  void equip(AWeapon*);
  void attack(AEnemy*);
  std::string const & getName() const;
};

#endif
