/*
** vertex.c for vertex in /home/dourches/Epitech/Seconde/Piscine/cpp_SKL/ex02
**
** Made by dourches
** Login   <martin.dourches@epitech.eu>
**
** Started on  Sat Jan  7 13:39:27 2017 dourches
** Last update Sun Jan  8 05:00:00 2017 Hugo Baldassin
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "raise.h"
#include "new.h"
#include "vertex.h"

typedef struct
{
  Class base;
  int x, y, z;
} VertexClass;

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

static char const *Vertex_to_string(Object *self)
{
  char *res;
  VertexClass *vertex;

  vertex = ((VertexClass *)self);
  if ((res = malloc(20 + lenNb(vertex->x) +
		    lenNb(vertex->y) + lenNb(vertex->z))) == NULL)
    raise("Malloc Error");
  sprintf(res,"<Vertex (%d, %d, %d)>", vertex->x,
	  vertex->y, vertex->z);
  return res;
}
static void Vertex_ctor(Object* self, va_list *args)
{
  VertexClass *vertex;

  vertex = (VertexClass*)self;
  vertex->x = va_arg(*args, int);
  vertex->y = va_arg(*args, int);
  vertex->z = va_arg(*args, int);
  va_end(*args);
}

static void Vertex_dtor(Object* self)
{
  (void) self;
}

static Object *Vertex_sub(const Object *self, const Object *other)
{
  return (new(Vertex, ((VertexClass *)self)->x - ((VertexClass *)other)->x,
	      ((VertexClass *)self)->y - ((VertexClass *)other)->y,
	      ((VertexClass *)self)->z - ((VertexClass *)other)->z));
}

static Object *Vertex_add(const Object *self, const Object *other)
{
  return (new(Vertex, ((VertexClass *)self)->x + ((VertexClass *)other)->x,
	      ((VertexClass *)self)->y + ((VertexClass *)other)->y,
	      ((VertexClass *)self)->z + ((VertexClass *)other)->z));
}

static VertexClass _description = {
  { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &Vertex_to_string, &Vertex_add, &Vertex_sub },
  0, 0, 0
};

Class* Vertex = (Class*) &_description;
