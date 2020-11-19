//
// LittlePony.cpp for LittlePony in /home/baldas/Prog/repos/tek2/piscine/rush/cpp_santa/src
// 
// Made by Hugo Baldassin
// Login   <hugo.baldassin@epitech.eu>
// 
// Started on  Sat Jan 14 15:31:48 2017 Hugo Baldassin
// Last update Sat Jan 14 22:51:36 2017 Hugo Willaume
//

#include	<iostream>
#include	"LittlePony.hh"

LittlePony::LittlePony(std::string const& title) :
  AToy(title, "Little Pony")
{
}

LittlePony::LittlePony(LittlePony const& littlePony) :
  AToy(littlePony._title, "Little Pony")
{
}

LittlePony& LittlePony::operator=(LittlePony const& littlePony)
{
  if (this != &littlePony)
    _title = littlePony._title;
  return *this;
}

LittlePony::~LittlePony()
{
}

void LittlePony::isTaken() const
{
  std::cout << "yo man" << std::endl;
}

IObject *LittlePony::clone() const
{
  return new LittlePony(_title);
}
