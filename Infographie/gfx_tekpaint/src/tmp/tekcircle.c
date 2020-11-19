/*
** tekcircle.c for tekcircle in /home/baldas_h/Prog/repos/info/gfx_fdf2
**
** Made by Hugo Baldassin
** Login   <baldas_h@epitech.net>
**
** Started on  Wed Dec 16 19:15:52 2015 Hugo Baldassin
** Last update Tue Jan 26 12:11:56 2016 baldas
*/

#include		<lapin.h>
#include		<math.h>
#include		"../../include/basics.h"

void			tekcircle(t_bunny_pixelarray *pix,
				  t_bunny_position *pos, double r, t_color *color)
{
  t_bunny_position	point;
  double		i;

  i = M_PI / 250;
  while (!(i > (2 * M_PI - 0.01) && i < (2 * M_PI + 0.01)))
    {
      point.x = pos->x + r * cos(i);
      point.y = pos->y + r * sin(i);
      tekpixel(pix, &point, color);
      i += M_PI / 250;
    }
  point.x = pos->x + r * cos(i);
  point.y = pos->y + r * sin(i);
  tekpixel(pix, &point, color);
}
