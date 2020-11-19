/*
** Ratatouille.h for  in /home/fortevg/rendu/piscine_cpp/cpp_d16/ex04
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Thu Jan 19 20:57:22 2017 Gabriel Forteville
** Last update Thu Jan 19 21:34:31 2017 Gabriel Forteville
*/

#ifndef _RATATOUILLE_H_
#define _RATATOUILLE_H_

#include <iostream>
#include <sstream>

class Ratatouille
{
 public:
  std::stringstream _result;

  Ratatouille();
  Ratatouille(Ratatouille const &);
  ~Ratatouille();
  Ratatouille &operator=(const Ratatouille &);

  Ratatouille &addVegetable(unsigned char);
  Ratatouille &addCondiment(unsigned int);
  Ratatouille &addSpice(double);
  Ratatouille &addSauce(const std::string &);

  std::string kooc(void);
};

#endif
