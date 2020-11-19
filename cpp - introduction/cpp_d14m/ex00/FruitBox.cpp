//
// FruitBox.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d14m/ex00
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Tue Jan 17 13:36:39 2017 Gabriel Forteville
// Last update Tue Jan 17 17:06:58 2017 Gabriel Forteville
//

#include <string>
#include "FruitBox.h"
#include "FruitNode.h"

FruitBox::FruitBox(int size):
  _size(size),
  _head(NULL)
{}

int FruitBox::nbFruits()
{
  FruitNode *tmp = _head;
  int fruits = 0;

  while (tmp != NULL)
    {
      tmp = tmp->next;
      fruits++;
    }
  return fruits;
}


bool FruitBox::putFruit(Fruit* fruit)
{
  FruitNode* tmp;

  if (nbFruits() == _size)
    return false;
  if (_head == NULL)
    {
      _head = new (FruitNode);
      _head->_fruit = fruit;
      _head->next = NULL;
      return true;
    }
  tmp = _head;
    do
    {
      if (tmp != NULL && tmp->_fruit == fruit)
	return false;
    }while (tmp != NULL && tmp->next != NULL && (tmp = tmp->next));
    tmp->next = new (FruitNode);
    tmp->next->_fruit = fruit;
    tmp->next->next = NULL;
    return true;
}

Fruit* FruitBox::pickFruit()
{
  Fruit* result = _head->_fruit;
  FruitNode *garbage = _head;
  _head = _head->next;
  delete(garbage);
  return (result);
}

FruitNode*  FruitBox::head() const
{
  return _head;
}

