/*
** String.c for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d03/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jan 06 09:33:45 2017 Forteville Gabriel
** Last update Fri Jan 06 23:01:17 2017 Forteville Gabriel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
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
  if (str && str->str)
    this->str = strdup(str->str);
}

static void assign_c(String* this, char const *s)
{
  if (!this->str)
    free(this->str);
  if (s)
    this->str = strdup(s);
}


static void append_s(String *this, String const *ap)
{
  if (!ap || !ap->str)
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
  if (this != NULL || this->str == NULL || pos > strlen(this->str) )
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


static int compare_s(String *this, const String *str)
{
  return (strcmp(this->str, str->str));
}

static int compare_c(String *this, char const *str)
{
  return (strcmp(this->str, str));
}


static size_t copy(String *this, char *s, size_t n, size_t pos)
{
  if (pos > strlen(this->str))
    return (0);
  s = strncpy(s, this->str + pos, n);
  return (n);
}

static char const *c_str(String *this)
{
  return (this->str);
}

static int empty(String *this)
{
  if (!this->str || strlen(this->str) != 0)
    return -1;
  return 1;
}

static int find_c(String *this, char const *str, size_t pos)
{
  char *ptr;

  if (!str || strlen(str) < pos)
    return -1;

  if ((ptr = strstr(this->str + pos, str)) == NULL)
    return -1;
  return (int)(ptr - this->str);
}

static int find_s(String *this, const String *str, size_t pos)
{
  if (!str)
    return -1;
  return find_c(this, str->str, pos);
}


static void insert_c(String *this, size_t pos, char const *str)
{
  if (!str || !this)
    return ;
  if (!this->str)
    {
      this->str = strdup(str);
      return ;
    }
  if (pos > strlen(str))
    {
      append_c(this, str);
      return ;
    }
  char *new_str = calloc(strlen(this->str) + strlen(this->str) + 1, 1);
  new_str = strncpy(new_str, this->str, pos);
  new_str = strcat(new_str, str);
  new_str = strcat(new_str, &(this->str[pos]));
  free(this->str);
  this->str = new_str;
}

static void insert_s(String *this, size_t pos, String const *str)
{
  if (!str)
    return ;
  insert_c(this, pos, str->str);
}

int to_int(String *this)
{
  return atoi(this->str);
}

void dump(String *this)
{
  if (this && this->str)
    write(1, this->str, strlen(this->str));
}

void StringInit(struct String *this, char const *s)
{
  if (s != NULL)
    this->str = strdup(s);

  if (this == NULL)
    return ;

  this->StringDestroy = &StringDestroy;

  this->assign_s = &assign_s;
  this->assign_c = &assign_c;

  this->append_s = &append_s;
  this->append_c = &append_c;

  this->at = &at;

  this->clear = &clear;

  this->size = &size;

  this->compare_c = &compare_c;
  this->compare_s = &compare_s;

  this->size = &size;

  this->copy = &copy;

  this->c_str = &c_str;

  this->empty = &empty;

  this->find_c = &find_c;
  this->find_s = &find_s;

  this->insert_s = &insert_s;
  this->insert_c = &insert_c;

  this->to_int = &to_int;

  this->dump = &dump;
}
