/*
** Fruit.h for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d14m/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 17 10:16:27 2017 Forteville Gabriel
** Last update Tue Jan 17 13:17:12 2017 Gabriel Forteville
*/

#ifndef __FRUIT_H_
#define __FRUIT_H_

#include <string>

class Fruit
{
 protected:
  int _vitamins;

 public:
  Fruit(int vitamins);
  virtual std::string getName() const = 0;
  int getVitamins();

}; /* Fruit */

#endif /* __FRUIT_H_ */
