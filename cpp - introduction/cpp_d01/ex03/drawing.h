/*
** drawing.h for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d01/ex03
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Jan 04 19:26:52 2017 Forteville Gabriel
** Last update Wed Jan 04 20:21:05 2017 Forteville Gabriel
*/

#include <stdint.h>
#include <stdlib.h>

#ifndef					DRAWING
# define 				DRAWING


typedef struct 	s_point
{
  int						x;
  int						y;
}								t_point;

void		draw_square(uint32_t **img, t_point *orig, size_t size, uint32_t color);

#endif
