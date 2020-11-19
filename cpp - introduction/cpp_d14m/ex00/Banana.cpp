/*
** Banana.cpp for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d14m/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 17 10:36:54 2017 Forteville Gabriel
// Last update Tue Jan 17 11:44:13 2017 Gabriel Forteville
*/

#include "Banana.h"

Banana::Banana():
  Fruit(5)
 {}

std::string Banana::getName() const { return "Banana"; }
