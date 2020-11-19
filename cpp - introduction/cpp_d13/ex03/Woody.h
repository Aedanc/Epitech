/*
** Woody.h for  in /home/fortevg/rendu/piscine_cpp/cpp_d13/ex00
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Mon Jan 16 13:36:01 2017 Gabriel Forteville
** Last update Mon Jan 16 14:36:59 2017 Gabriel Forteville
*/

#ifndef _WOODY_H_
#define _WOODY_H_

#include <string>
#include "Toy.h"

class Woody : public Toy
{

 public:
  Woody(std::string name, std::string file = "woody.txt");
  virtual ~Woody();

  virtual void speak(std::string const& sentence);
};

#endif
