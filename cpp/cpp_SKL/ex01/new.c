/*
** new.c for  in /home/hurlu/rendu/cpp_SKL/ex01
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sat Jan  7 10:58:28 2017 Hugo Willaume
** Last update Sun Jan  8 05:31:11 2017 Hugo Willaume
*/

#include <stdlib.h>
#include <string.h>
#include "raise.h"
#include "point.h"
#include "new.h"
#include "raise.h"

void *new(Class *class)
{
  Object *new_instance;

  if ((new_instance = malloc(class->__size__)) == NULL)
    raise("Malloc Error");
  memcpy(new_instance, class, class->__size__);
  class->__init__(new_instance);
  return new_instance;
}

void delete(Object *instance)
{
  ((Class *)instance)->__del__(instance);
  free(instance);
}
