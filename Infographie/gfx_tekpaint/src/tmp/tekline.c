/*
** tekline.c for tekline in /home/baldas_h/Prog/infographie/test tekline
**
** Made by Hugo Baldassin
** Login   <baldas_h@epitech.net>
**
** Started on  Mon Dec 14 10:58:40 2015 Hugo Baldassin
** Last update Tue Jan 26 21:06:14 2016 baldas
*/

#include		<lapin.h>
#include		<lapin_enum.h>

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos, t_color *color);

int			abscisse(int c)
{
  if (c < 0)
    return (-c);
  return (c);
}

void			initline(t_bunny_position *draw,
				 t_bunny_position *pos, int *a, int *b)
{
  draw->x = pos[0].x;
  draw->y = pos[0].y;
  *a = abscisse(pos[1].x - draw->x);
  *b = abscisse(pos[1].y - draw->y);
}

void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos, t_color *color)
{
  t_bunny_position	draw;
  int			a;
  int			b;
  int			err;
  int			e2;

  tekpixel(pix, &pos[1], color);
  initline(&draw, pos, &a, &b);
  err = (a > b ? a / 2 : -b / 2);
  while (draw.x != pos[1].x || draw.y != pos[1].y)
    {
      tekpixel(pix, &draw, color);
      e2 = err;
      if (e2 > -a)
	{
	  err = err - b;
	  draw.x = draw.x + (draw.x < pos[1].x ? 1 : -1);
	}
      if (e2 < b)
	{
	  err = err + a;
	  draw.y = draw.y + (draw.y < pos[1].y ? 1 : -1);
	}
    }
}
