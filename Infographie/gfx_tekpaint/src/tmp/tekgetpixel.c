/*
** tekgetpixel.c for  in /home/hurlu/rendu/xorshape_2020
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Wed Dec  2 09:19:07 2015 Hugo Willaume
** Last update Tue Jan 26 20:45:19 2016 Hugo Willaume
*/

#include <lapin.h>

unsigned int	tekgetpixel(t_bunny_pixelarray *pix,
			    t_bunny_position *pos)
{
  unsigned int	*my_pixs;

  my_pixs = (unsigned int *)pix->pixels;
  return (my_pixs[pos->y * pix->clipable.buffer.width + pos->x]);
}
