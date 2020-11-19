/*
** point.c<ex02> for point in /home/dourches/Epitech/Seconde/Piscine/cpp_SKL
**
** Made by dourches
** Login   <martin.dourches@epitech.eu>
**
** Started on  Sat Jan  7 13:30:21 2017 dourches
** Last update Sun Jan  8 05:40:58 2017 Hugo Willaume
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "point.h"
#include "raise.h"

typedef struct
{
    Class base;
    int x, y;
} PointClass;

static void Point_ctor(Object* self, va_list *args)
{
  PointClass *point;

  point = (PointClass*)self;
  point->x = va_arg(*args, int);
  point->y = va_arg(*args, int);
  va_end(*args);
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

static char const *Point_to_string(Object *self)
{
  char *res;
  PointClass *point;

  point = (PointClass *)self;
  if ((res = malloc(17 + lenNb(point->x)) +
       lenNb(point->y)) == NULL)
    raise("Malloc Error");
  sprintf(res,"<Point (%d, %d)>", point->x, point->y);
  return res;
}

static void Point_dtor(Object* self)
{
    (void) self;
}

static PointClass _description = {
  { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &Point_to_string },
    0, 0
};

Class* Point = (Class*) &_description;
