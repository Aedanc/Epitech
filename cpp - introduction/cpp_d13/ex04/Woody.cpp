//
// Woody.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d13/ex02
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Mon Jan 16 13:44:42 2017 Gabriel Forteville
// Last update Mon Jan 16 14:39:47 2017 Gabriel Forteville
//

#include <iostream>
#include <fstream>
#include "Woody.h"

Woody::Woody(std::string name, std::string file):
  Toy(WOODY, name, file)
{

}

Woody::~Woody() {}

void Woody::speak(std::string const& sentence)
{
  std::cout << "WOODY: " << _name << " \"" << sentence << "\"" << std::endl;
 }
