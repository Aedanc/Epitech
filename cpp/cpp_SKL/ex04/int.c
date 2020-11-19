/*
** int.c for int in /home/dourches/Epitech/Seconde/Piscine/cpp_SKL/ex04
**
** Made by dourches
** Login   <martin.dourches@epitech.eu>
**
** Started on  Sat Jan  7 17:11:20 2017 dourches
** Last update Sun Jan  8 07:17:28 2017 Hugo Willaume
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "raise.h"
#include "bool.h"
#include "int.h"
#include "new.h"

typedef struct
{
  Class base;
  int value;
} IntClass;

static void Int_ctor(Object* self, va_list *args)
{
  IntClass *integer;

  integer = (IntClass*)self;
  integer->value = va_arg(*args, int);
  va_end(*args);
}

static Object* add_int(const Object *p1, const Object* p2)
{
  return new(Int, ((IntClass *)p1)->value + ((IntClass *)p2)->value);
}

static Object *sub_int(const Object *p1, const Object *p2)
{
  return new(Int, ((IntClass *)p1)->value - ((IntClass *)p2)->value);
}

static int      eq_int(const Object *p1, const Object *p2)
{
  if (((IntClass*)p1)->value == ((IntClass*)p2)->value)
    return (true);
  return (false);
}

static int      lt_int(const Object *p1, const Object *p2)
{
  if (((IntClass*)p1)->value < ((IntClass*)p2)->value)
    return (true);
  return (false);
}

static bool      gt_int(const Object *p1, const Object *p2)
{
  if (((IntClass*)p1)->value > ((IntClass*)p2)->value)
    return (true);
  return (false);
}

static Object *mul_int(const Object *p1, const Object* p2)
{
  return new(Int, ((IntClass *)p1)->value * ((IntClass *)p2)->value);
}

static Object *div_int(const Object *p1, const Object *p2)
{
  if (((IntClass *)p2)->value == 0)
    raise("Attempted integer division by zero");
  return new(Int, ((IntClass *)p1)->value / ((IntClass *)p2)->value);
}

static int lenNb(int nb)
{
  int len = 0;

  while (nb > 0)
    {
      nb /= 10;
      len++;
    }
  return len;
}

static char const *Int_to_string(Object *self)
{
  char *res;

  if ((res = malloc(12 + lenNb(((IntClass*)self)->value))) == NULL)
    raise("Malloc Error");
  sprintf(res,"<Int (%d)>", ((IntClass*)self)->value);
  return res;
}

static void Int_dtor(Object* self)
{
    (void) self;
}

static IntClass _description = {
  { sizeof(IntClass), "Int", &Int_ctor, &Int_dtor, &Int_to_string ,
    &add_int, &sub_int, &mul_int, &div_int,
    &eq_int, &gt_int, &lt_int}, 0
};

Class* Int = (Class*) &_description;
