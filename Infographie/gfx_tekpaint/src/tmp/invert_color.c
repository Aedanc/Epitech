/*
** invert_color.c for invert_color in /home/baldas/Prog/repos/info/gfx_tekpaint/src/tmp
**
** Made by baldas
** Login   <baldas@epitech.net>
**
** Started on  Tue Jan 26 15:16:09 2016 baldas
** Last update Tue Jan 26 15:23:47 2016 baldas
*/

#include	<lapin.h>

void		invert_color(t_bunny_pixelarray *pix)
{
  unsigned int	*pixel;
  int		i;

  i = -1;
  pixel = (unsigned int *)pix->pixels;
  while (++i < pix->clipable.buffer.width * pix->clipable.buffer.height)
    pixel[i] = 0xFFFFFFFF - pixel[i];
}
