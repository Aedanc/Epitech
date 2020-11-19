//
// PlasmaRifle.hh for  in /home/fortevg/rendu/piscine_cpp/cpp_d10/ex01
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Fri Jan 13 15:03:01 2017 Gabriel Forteville
// Last update Fri Jan 13 15:55:14 2017 Gabriel Forteville
//

#ifndef __PLASMARIFLE_HH_
#define __PLASMARIFLE_HH_

#include <iostream>
#include "AWeapon.hh"

class PlasmaRifle : public AWeapon
{
private:
  std::string _sound;
public:
  PlasmaRifle();
  virtual ~PlasmaRifle();
  virtual void attack() const;
};

#endif

