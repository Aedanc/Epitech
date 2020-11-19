/*
** drawing.c for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d01/ex03
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Jan 04 19:37:23 2017 Forteville Gabriel
** Last update Thu Jan 05 10:11:06 2017 Forteville Gabriel
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "drawing.h"

void		draw_square(uint32_t **img, t_point *orig, size_t size, uint32_t color)
{
  size_t i;
  size_t j;

    for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++) {
          img[orig->y + i][orig->x + j] = color;
      }
    }
}
