//
// Teddy.hh for  in /home/fortevg/rendu/piscine_cpp/cpp_santa/includes
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Sat Jan 14 15:33:18 2017 Gabriel Forteville
// Last update Sat Jan 14 22:42:01 2017 Hugo Willaume
//

#ifndef __TEDDY_HH_
# define __TEDDY_HH_

#include <iostream>
#include <string>
#include "AToy.hh"

class Teddy : public AToy
{
private:

protected:

public:
  Teddy(std::string title);
  Teddy(Teddy const& other);
  ~Teddy();

  virtual void isTaken() const;

  virtual IObject *clone() const;
  Teddy & operator=(Teddy const& other);
};

#endif
