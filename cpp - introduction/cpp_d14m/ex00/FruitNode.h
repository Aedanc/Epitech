/*
** FruitNode.h for  in /home/fortevg/rendu/piscine_cpp/cpp_d14m/ex00
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Tue Jan 17 13:29:22 2017 Gabriel Forteville
** Last update Tue Jan 17 17:05:47 2017 Gabriel Forteville
*/

#ifndef __FRUITNODE_H_
# define __FRUITNODE_H_

#include "Fruit.h"

typedef struct FruitNode {
  Fruit *_fruit;
  FruitNode *next;
} FruitNode;

#endif
