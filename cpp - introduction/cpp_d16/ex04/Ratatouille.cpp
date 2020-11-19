//
// Ratatouille.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d16/ex04
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Thu Jan 19 20:59:44 2017 Gabriel Forteville
// Last update Fri Jan 20 09:15:28 2017 Gabriel Forteville
//

#include <iostream>
#include <sstream>
#include "Ratatouille.h"

Ratatouille::Ratatouille() {}

Ratatouille::Ratatouille(Ratatouille const &other) {
  _result.str("");
  _result << other._result.str();
}

Ratatouille::~Ratatouille()
{}

Ratatouille &Ratatouille::operator=(const Ratatouille & other)
{
  if (&other == this)
    return *this;
  _result.str("");
  _result << other._result.str();
  return *this;
}

Ratatouille &Ratatouille::addVegetable(unsigned char str)
{
  _result << str;
  return *this;
}

Ratatouille &Ratatouille::addCondiment(unsigned int value)
{
  _result << value;
  return *this;
}

Ratatouille &Ratatouille::addSpice(double value)
{
  _result << value;
  return *this;
}

Ratatouille &Ratatouille::addSauce(const std::string &value)
{
  _result << value;
  return *this;
}

std::string Ratatouille::kooc()
{
  return _result.str();
}
