/*
** String.c for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d03/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jan 06 09:33:45 2017 Forteville Gabriel
** Last update Fri Jan 06 10:09:49 2017 Forteville Gabriel
*/

#include <stdlib.h>
#include <string.h>
#include "String.h"

void StringDestroy(struct String *this)
{
  if (this->str != NULL)
    free(this->str);
  this->str = NULL;
}

static void assign_s(String *this, String const *str)
{
  if (!this->str)
    free(this->str);
  this->str = strdup(str->str);
}

static void assign_c(String* this, char const *s)
{
  if (!this->str)
    free(this->str);
  this->str = strdup(s);
}

void StringInit(struct String *this, char const *s)
{
  this->str = strdup(s);
  this->StringDestroy = &StringDestroy;
  this->assign_s = &assign_s;
  this->assign_c = &assign_c;
}
