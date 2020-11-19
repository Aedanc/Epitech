/*
** now_put_square.c for  in /home/fortevg/rendu/CPE/CPE_2015_BSQ
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sat Dec 19 20:26:19 2015 Forteville Gabriel
** Last update Sat Dec 19 23:08:16 2015 Forteville Gabriel
*/

#include <unistd.h>
#include "my.h"

void		put_on_screen(t_list *square, char **map)
{
  square->lenghtmap--;
  while (map[square->y] != NULL)
    {
      write(1, map[square->y], square->lenghtmap);
      write(1, "\n", 1);
      square->y++;
    }
}

void		now_put_the_square(t_list *square, char **map)
{
  square->y = square->ymax;
  while (square->y < square->ymax + square->sizemax)
    {
      square->x = square->xmax;
      while (square->x < square->xmax + square->sizemax)
	{
	  map[square->y][square->x] = 'x';
	  square->x++;
	}
      square->y++;
    }
  square->y = 0;
  square->x = 0;
  put_on_screen(square, map);
}
