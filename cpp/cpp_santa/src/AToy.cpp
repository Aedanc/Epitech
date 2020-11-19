//
// AToy.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_santa/src
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Sat Jan 14 14:09:57 2017 Gabriel Forteville
// Last update Sat Jan 14 21:35:34 2017 Gabriel Forteville
//

#include <iostream>
#include "AToy.hh"

AToy::AToy(std::string title, std ::string name): AObject(name, title)
{

}

AToy::AToy(AToy const& other): AObject("Atoy", other._title)
{

}

AToy::~AToy()
{

}

AToy& AToy::operator=(AToy const& other)
{
  if (this == &other)
    return *this;
  _title = other._title;
  return *this;
}
