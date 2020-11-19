/*
** banana.h for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d14m/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 17 10:22:40 2017 Forteville Gabriel
** Last update Tue Jan 17 13:16:48 2017 Gabriel Forteville
*/

#ifndef __BANANA_H_
#define __BANANA_H_

#include <string>
#include "Fruit.h"

class Banana : public Fruit {

 public:
  Banana();
  std::string getName() const;

}; /* banana */

#endif /* __BANANA_H_ */
