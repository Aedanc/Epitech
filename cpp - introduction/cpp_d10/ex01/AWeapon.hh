//
// AWeapon.hh for  in /home/fortevg/rendu/piscine_cpp/cpp_d10/ex01
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Fri Jan 13 14:21:33 2017 Gabriel Forteville
// Last update Fri Jan 13 15:45:49 2017 Gabriel Forteville
//

#ifndef __AWEAPON_HH_
#define __AWEAPON_HH_

#include <iostream>

class AWeapon
{
private:
  std::string _name;
  int _damage;
  int _cost;

public:
  AWeapon(std::string const & name, int apcost, int damage);
  virtual ~AWeapon();
  std::string const getName() const;
  int getAPCost() const;
  int getDamage() const;
  virtual  void attack() const = 0;
};

#endif
