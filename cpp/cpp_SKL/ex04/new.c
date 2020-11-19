/*
** new.c for  in /home/hurlu/rendu/cpp_SKL/ex01
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sat Jan  7 10:58:28 2017 Hugo Willaume
** Last update Sun Jan  8 05:08:26 2017 Gabriel Forteville
*/


#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "raise.h"
#include "new.h"


void *va_new(Class *class, va_list *ap)
{
  Object *new_instance;

  if ((new_instance = malloc(class->__size__)) == NULL)
    raise("Malloc Error");
  memcpy(new_instance, class, class->__size__);
  class->__init__(new_instance, ap);
  return new_instance;
}

void *new(Class *class, ...)
{
  Object *new_instance;
  va_list ap;

  va_start(ap, class);
  if ((new_instance = malloc(class->__size__)) == NULL)
    raise("Malloc Error");
  memcpy(new_instance, class, class->__size__);
  class->__init__(new_instance, &ap);
  return new_instance;
}

void delete(Object *instance)
{
  ((Class *)instance)->__del__(instance);
  free(instance);
}
