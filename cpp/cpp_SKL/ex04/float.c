/*
** float.c for float in /home/dourches/Epitech/Seconde/Piscine/cpp_SKL/ex04
**
** Made by dourches
** Login   <martin.dourches@epitech.eu>
**
** Started on  Sat Jan  7 16:57:04 2017 dourches
** Last update Sun Jan  8 07:17:57 2017 Hugo Willaume
*/

#include <float.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "float.h"
#include "raise.h"
#include "new.h"

typedef struct
{
  Class base;
  float value;
} FloatClass;

static void Float_ctor(Object* self, va_list *args)
{
  FloatClass *floating_integer;

  floating_integer = (FloatClass*)self;
  floating_integer->value = va_arg(*args, double);
  va_end(*args);
}

static Object* add_float(const Object *p1, const Object* p2)
{
  return new(Float, ((FloatClass *)p1)->value + ((FloatClass *)p2)->value);
}

static Object *sub_float(const Object *p1, const Object *p2)
{
  return new(Float, ((FloatClass *)p1)->value - ((FloatClass *)p2)->value);
}

static int	eq_float(const Object *p1, const Object *p2)
{
  if (((FloatClass*)p1)->value == ((FloatClass*)p2)->value)
    return (true);
  return (false);
}

static int	lt_float(const Object *p1, const Object *p2)
{
  if (((FloatClass*)p1)->value < ((FloatClass*)p2)->value)
    return (true);
  return (false);
}

static int	gt_float(const Object *p1, const Object *p2)
{
  if (((FloatClass*)p1)->value > ((FloatClass*)p2)->value)
    return (true);
  return (false);
}

static Object* mul_float(const Object *p1, const Object* p2)
{
  return new(Float, ((FloatClass *)p1)->value * ((FloatClass *)p2)->value);
}

static Object* div_float(const Object *p1, const Object* p2)
{
  if (((FloatClass *)p2)->value == 0)
    raise("Attempted float division by zero");
  return new(Float, ((FloatClass *)p1)->value / ((FloatClass *)p2)->value);
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

static char const *Float_to_string(Object *self)
{
  char *res;
  if ((res = malloc(lenNb(((FloatClass *)self)->value) + 20)) == NULL)
    raise("Malloc Error");
  sprintf(res, "<Float (%f)>", ((FloatClass *)self)->value);
  return res;
}

static void Float_dtor(Object* self)
{
    (void) self;
}

static FloatClass _description = {
  { sizeof(FloatClass), "Float", &Float_ctor, &Float_dtor, &Float_to_string ,
    &add_float, &sub_float, &mul_float, &div_float,
    &eq_float, &gt_float, &lt_float}, 0
};

Class* Float = (Class*) &_description;
