/*
** String.c for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d03/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jan 06 09:33:45 2017 Forteville Gabriel
** Last update Fri Jan 06 11:13:56 2017 Forteville Gabriel
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


static void append_s(String *this, String const *ap)
{
  if (!ap && !ap->str)
    return ;
  this->str = realloc(this->str, strlen(this->str) + strlen(ap->str));

  this->str = strcat(this->str, ap->str);
}

static void append_c(String *this, char const *aps)
{
  if (!aps)
    return ;
  this->str = realloc(this->str, strlen(this->str) + strlen(aps));

  this->str = strcat(this->str, aps);
}


static char at(String *this, size_t pos)
{
  if (this->str == NULL || pos > strlen(this->str) )
    return (-1);
  return (this->str[pos]);
}


static void clear(String *this)
{
  if (!this->str)
    free(this->str);
  this->str = strdup("");
}


static int size(String *this)
{
  if (!this->str)
    return (-1);
  return (strlen(this->str));
}

void StringInit(struct String *this, char const *s)
{
  this->str = strdup(s);

  this->StringDestroy = &StringDestroy;

  this->assign_s = &assign_s;
  this->assign_c = &assign_c;

  this->append_s = &append_s;
  this->append_c = &append_c;

  this->at = &at;

  this->clear = &clear;

  this->size = &size;
}
