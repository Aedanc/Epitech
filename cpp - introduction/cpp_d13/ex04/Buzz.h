/*
** Buzz.h for  in /home/fortevg/rendu/piscine_cpp/cpp_d13/ex00
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Mon Jan 16 13:36:01 2017 Gabriel Forteville
** Last update Mon Jan 16 14:28:17 2017 Gabriel Forteville
*/

#ifndef _BUZZ_H_
#define _BUZZ_H_

#include <string>
#include "Toy.h"

class Buzz : public Toy
{

 public:
  Buzz(std::string name, std::string file = "buzz.txt");
  virtual ~Buzz();

  virtual void speak(std::string const& sentence);
};

#endif
