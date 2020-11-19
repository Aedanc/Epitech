//
// Victim.hh for  in /home/fortevg/rendu/piscine_cpp/cpp_d09/ex02
//
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
//
// Started on  Fri Jan 13 10:48:51 2017 Gabriel Forteville
// Last update Fri Jan 13 13:37:53 2017 Gabriel Forteville
//

#ifndef __VICTIM_HH_
#define __VICTIM_HH_

#include <iostream>

class Victim {

protected:
  std::string _name;

public :
  Victim(std::string name);
  Victim(Victim const & other);
  virtual ~Victim();

  virtual void getPolymorphed() const;

  std::string getName() const;
};

  std::ostream& operator<<(std::ostream& os, Victim const& victime);

#endif
