//
// SuperMutant.hh for  in /home/fortevg/rendu/piscine_cpp/cpp_d10/ex01
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Fri Jan 13 16:59:38 2017 Gabriel Forteville
// Last update Fri Jan 13 23:14:42 2017 Gabriel Forteville
//

#ifndef __SUPERMUTANT_HH_
#define __SUPERMUTANT_HH_

#include <iostream>
#include "AEnemy.hh"

class SuperMutant : public AEnemy
{
public:
  SuperMutant();
  ~SuperMutant();

  void takeDamage(int damage);
};

#endif
