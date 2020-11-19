/*
** tekgetpixel.c for  in /home/fortevg/rendu/infographi/xorshape_2020
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Dec  2 09:27:14 2015 Forteville Gabriel
** Last update Sun Feb 28 15:30:00 2016 Forteville Gabriel
*/

#include <lapin.h>

unsigned int	tekgetpixel(t_bunny_pixelarray *pix,
			    t_bunny_position *pos)
{
  unsigned int	*color;

  color = (unsigned int	*)pix->pixels;
  return (color[pos->y * pix->clipable.buffer.width + pos->x]);
}
