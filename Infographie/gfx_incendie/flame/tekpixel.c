/*
** rectangle.c for infodemerde in /home/fortev_g/Desktop
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Wed Nov  4 10:42:25 2015 Gabriel Forteville
** Last update Sat Dec  5 16:52:01 2015 Forteville Gabriel
*/
#include <lapin.h>
#include <unistd.h>

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color color)
{
  t_color	*wololo;

  wololo = pix->pixels;
  wololo[pos[0].x + pos[0].y * pix->clipable.buffer.width] = color;
}
