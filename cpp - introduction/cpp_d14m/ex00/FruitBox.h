/*
** FruitBox.h for  in /home/fortevg/rendu/piscine_cpp/cpp_d14m/ex00
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Tue Jan 17 12:07:40 2017 Gabriel Forteville
** Last update Tue Jan 17 14:59:41 2017 Gabriel Forteville
*/

#ifndef _FRUITBOX_H_
# define _FRUITBOX_H_

# include <string>
# include "FruitNode.h"
# include "Fruit.h"

class FruitBox
{
 protected:
  int _size;
  FruitNode* _head;

 public:
  FruitBox(int size);
  int nbFruits();
  bool putFruit(Fruit* f);
  Fruit* pickFruit();
  FruitNode *head() const;
};

#endif
