/*
** Lemon.h for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d14m/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 17 10:22:40 2017 Forteville Gabriel
** Last update Tue Jan 17 13:16:52 2017 Gabriel Forteville
*/

#ifndef __LEMON_H_
#define __LEMON_H_

#include <string>
#include "Fruit.h"

class Lemon : public Fruit {
public:
  Lemon();
  std::string getName() const;

}; /* Lemon */
#endif /* __LEMON_H_ */
