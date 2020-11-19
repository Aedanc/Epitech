//
// Teddy.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_santa/src
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Sat Jan 14 15:57:53 2017 Gabriel Forteville
// Last update Sat Jan 14 22:51:49 2017 Hugo Willaume
//

#include <iostream>
#include <string>
#include "Teddy.hh"

Teddy::Teddy(std::string title):
  AToy(title, "Teddy")
{}

Teddy::Teddy(Teddy const& other):
  AToy(other._title, "Teddy")
{}

Teddy::~Teddy()
{}

void Teddy::isTaken() const
{
  std::cout << "gra hu" << std::endl;
}

Teddy & Teddy::operator=(Teddy const& other)
{
  _title = other._title;
  return *this;
}

IObject *Teddy::clone() const
{
  return new Teddy(_title);
}
