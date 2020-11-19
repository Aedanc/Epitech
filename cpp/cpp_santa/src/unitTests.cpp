//
// unitTests.cpp for unitTests in /home/baldas/Prog/repos/tek2/piscine/rush/cpp_santa/src
// 
// Made by Hugo Baldassin
// Login   <hugo.baldassin@epitech.eu>
// 
// Started on  Sun Jan 15 01:52:27 2017 Hugo Baldassin
// Last update Sun Jan 15 02:52:39 2017 Hugo Baldassin
//

#include	"Box.hh"
#include	"GiftPaper.hh"
#include	"Teddy.hh"
#include	"LittlePony.hh"

IObject **MyUnitTests()
{
  IObject **toys = new IObject* [2];

  toys[0] = new LittlePony("gay pony");
  toys[1] = new Teddy("bisounours");
  return toys;
}

IObject *MyUnitTests(IObject **objects)
{
  ((Box *)objects[1])->wrapMeThat(objects[0]);
  ((GiftPaper *)objects[2])->wrapMeThat(objects[1]);
  return objects[2];
}
