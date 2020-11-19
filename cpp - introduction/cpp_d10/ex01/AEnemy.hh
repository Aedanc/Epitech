//
// AEnemy.hh for  in /home/fortevg/rendu/piscine_cpp/cpp_d10/ex01
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Fri Jan 13 16:15:37 2017 Gabriel Forteville
// Last update Fri Jan 13 23:40:11 2017 Gabriel Forteville
//

#ifndef __AENEMY_HH_
#define __AENEMY_HH_

#include <iostream>

class AEnemy
{
protected:
  int _hp;
  std::string _type;

public:
  AEnemy(int hp, std::string const & type);
  virtual ~AEnemy();
  std::string const  getType() const;
  int getHP() const;

  virtual void takeDamage(int);
};

#endif
