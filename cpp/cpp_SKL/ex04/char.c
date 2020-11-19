/*
** char.c for char in /home/dourches/Epitech/Seconde/Piscine/cpp_SKL/ex04
**
** Made by dourches
** Login   <martin.dourches@epitech.eu>
**
** Started on  Sat Jan  7 17:12:28 2017 dourches
** Last update Sun Jan  8 07:18:25 2017 Hugo Willaume
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "raise.h"
#include "char.h"
#include "new.h"
#include "bool.h"

typedef struct
{
  Class base;
  char value;
} CharClass;

static void Char_ctor(Object* self, va_list *args)
{
  CharClass *character;

  character = (CharClass*)self;
  character->value = va_arg(*args, int);
  va_end(*args);
}

static Object* add_char(const Object *p1, const Object* p2)
{
  int check;

  return new(Char, ((char)((CharClass *)p1)->value + ((CharClass *)p2)->value));
}

static Object *sub_char(const Object *p1, const Object *p2)
{
  int check;

  return new(Char, ((CharClass *)p1)->value - ((CharClass *)p2)->value);
}

static Object *mul_char(const Object *p1, const Object *p2)
{
  return new(Char, ((CharClass *)p1)->value * ((CharClass *)p2)->value);
}

static Object *div_char(const Object *p1, const Object *p2)
{
  if (((CharClass *)p2)->value == 0)
    raise("char division by 0.\n");
  return new(Char, ((CharClass *)p1)->value / ((CharClass *)p2)->value);
}

static int      eq_char(const Object *p1, const Object *p2)
{
  if (((CharClass*)p1)->value == ((CharClass*)p2)->value)
    return (true);
  return (false);
}

static int      lt_char(const Object *p1, const Object *p2)
{
  if (((CharClass*)p1)->value < ((CharClass*)p2)->value)
    return (true);
  return (false);
}

static int      gt_char(const Object *p1, const Object *p2)
{
  if (((CharClass*)p1)->value > ((CharClass*)p2)->value)
    return (true);
  return (false);
}

static char const *Char_to_string(Object *self)
{
  char *str;

  if ((str = malloc(11)) == NULL)
    raise("Malloc Error");
  sprintf(str, "<Char (%d)>", ((int)((CharClass*)self)->value));
  return str;
}

static void Char_dtor(Object* self)
{
    (void) self;
}

static CharClass _description = {
  { sizeof(CharClass), "Char", &Char_ctor, &Char_dtor, &Char_to_string ,
    &add_char, &sub_char, &mul_char, &div_char,
    &eq_char, &gt_char, &lt_char}, 0
};

Class* Char = (Class*) &_description;
