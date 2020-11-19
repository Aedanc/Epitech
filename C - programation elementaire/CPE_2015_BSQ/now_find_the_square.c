/*
** now_find_the_square.c for  in /home/fortevg/rendu/CPE/CPE_2015_BSQ
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Dec 16 14:18:42 2015 Forteville Gabriel
** Last update Sun Dec 20 00:42:27 2015 Forteville Gabriel
*/

#include <stdio.h>
#include "my.h"

int		checkinside(t_list *square, char **map)
{
  t_list	tmp;
  int		yandsize;
  int		xandsize;

  tmp = *square;
  yandsize = tmp.y + tmp.size;
  xandsize = tmp.x + tmp.size;
  while (tmp.y <= yandsize - 1)
    {
      if (map[tmp.y][xandsize] == 'o')
	return (1);
      tmp.y++;
    }
  while (tmp.x <= xandsize)
    {
      if (map[yandsize][tmp.x] == 'o')
	return (1);
      tmp.x++;
    }
  return (0);
}

char		**now_find_the_square(t_list *square, char **map, int nbrline)
{
  while (square->y < nbrline)
    {
      while (map[square->y][square->x] != '\0')
	{
	  square->size = 1;
	  if (map[square->y][square->x] != 'o')
	    {
	      while (square->y + square->size < nbrline &&
		     checkinside(square, map) == 0 &&
		     map[square->y][square->x + square->size] == '.' &&
		     map[square->y + square->size][square->x] == '.')
		square->size++;
	      if (square->sizemax < square->size)
		{
		  square->sizemax = square->size;
		  square->xmax = square->x;
		  square->ymax = square->y;
		}
	    }
	  square->x = square->x + square->size;
	}
      square->x = 0;
      square->y++;
    }
  return (map);
}
