//
// Peon.hh for  in /home/fortevg/rendu/piscine_cpp/cpp_d10/ex00
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Fri Jan 13 13:09:25 2017 Gabriel Forteville
// Last update Fri Jan 13 21:38:59 2017 Gabriel Forteville
//

#ifndef __PEON_HH_
#define __PEON_HH_

#include <iostream>
#include "Victim.hh"

class Peon : public Victim
{
public:
  Peon(std::string name);
  ~Peon();

  virtual void getPolymorphed() const;
};

#endif
