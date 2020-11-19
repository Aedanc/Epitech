//
// Buzz.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d13/ex02
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Mon Jan 16 13:44:42 2017 Gabriel Forteville
// Last update Mon Jan 16 14:44:26 2017 Gabriel Forteville
//

#include <iostream>
#include <fstream>
#include "Buzz.h"

Buzz::Buzz(std::string name, std::string file):
  Toy(BUZZ, name, file)
{

}

Buzz::~Buzz() {}

void Buzz::speak(std::string const& sentence)
{
 std::cout << "Buzz: " << _name << " \"" << sentence << "\"" << std::endl;
}
