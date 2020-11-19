/*
** Toy.h for  in /home/fortevg/rendu/piscine_cpp/cpp_d13
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Mon Jan 16 10:32:12 2017 Gabriel Forteville
** Last update Mon Jan 16 14:28:24 2017 Gabriel Forteville
*/

#ifndef _TOY_H_
#define _TOY_H_

#include <string>
#include "Picture.h"

class Toy
{

 public:
  enum ToyType {BASIC_TOY, ALIEN, WOODY, BUZZ};
  ToyType const _type;
  std::string _name;
  Picture _picture;

  Toy();
  Toy(ToyType const type, std::string const& name, std::string const& file);
  virtual ~Toy();

  virtual void speak(std::string const& sentence);

  ToyType getType() const;
  std::string const& getName() const;
  void setName(std::string const& name);
  bool setAscii(std::string const& file);
  std::string const& getAscii() const;
};

#endif
