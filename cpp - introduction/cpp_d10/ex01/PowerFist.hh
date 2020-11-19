//
// PowerFist.hh for  in /home/fortevg/rendu/piscine_cpp/cpp_d10/ex01
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Fri Jan 13 15:03:01 2017 Gabriel Forteville
// Last update Fri Jan 13 16:12:23 2017 Gabriel Forteville
//

#ifndef __POWERFIST_HH_
#define __POWERFIST_HH_

#include <iostream>
#include "AWeapon.hh"

class PowerFist : public AWeapon
{
private:
  std::string _sound;
public:
  PowerFist();
  virtual ~PowerFist();
  virtual void attack() const;
};

#endif

