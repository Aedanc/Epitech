/*
** set_color.c for set_color in /home/baldas/Prog/repos/info/gfx_tekpaint/src/tmp
**
** Made by baldas
** Login   <baldas@epitech.net>
**
** Started on  Tue Jan 26 12:26:14 2016 baldas
** Last update Tue Jan 26 12:26:27 2016 baldas
*/

#include <lapin.h>

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos, t_color *color);

void			set_color(t_bunny_pixelarray *pix, unsigned int color)
{
  unsigned int *pixel;
  int		i;

  pixel = pix->pixels;
  i = -1;
  while ((++i) < pix->clipable.buffer.width * pix->clipable.buffer.height)
    pixel[i] = color;
}
