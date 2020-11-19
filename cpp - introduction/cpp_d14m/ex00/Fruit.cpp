/*
** Fruit.cpp for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d14m/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 17 10:29:30 2017 Forteville Gabriel
// Last update Tue Jan 17 13:14:27 2017 Gabriel Forteville
*/

#include <string>
#include "Fruit.h"

Fruit::Fruit(int vitamins):
  _vitamins(vitamins)
{}

int Fruit::getVitamins() { return _vitamins; }

