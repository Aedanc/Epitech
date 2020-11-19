/*
** rectangle.c for infodemerde in /home/fortev_g/Desktop
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Wed Nov  4 10:42:25 2015 Gabriel Forteville
** Last update Wed Dec 23 09:25:19 2015 Forteville Gabriel
*/

#include <lapin.h>
#include <unistd.h>

t_color		*setpixel(t_bunny_pixelarray *pix, t_bunny_position *pos,
			  t_color *color, t_color *wololo)
{
  t_color	getcolor;
   t_color	result;
  int		i;

  getcolor = wololo[pos[0].x + pos[0].y * pix->clipable.buffer.width];
  if (color->argb[3] == 0)
    exit (0);
  else if (getcolor.argb[3] == 0)
    return (color);
  i = 0;
  while (i != 3)
    {
      result.argb[i] = (color->argb[i] * color->argb[3]
			+ (getcolor.argb[i] * getcolor.argb[3]) * (1 - color->argb[3]))
	/ (color->argb[3] + getcolor.argb[3] * (1 - color->argb[3]));
      i++;
    }
  return (&result);
}

void		teksetpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color)
{
  t_color	*wololo;

  wololo = pix->pixels;
  if (color->argb[3] != 255)
    {
      color = setpixel(pix, pos, color, wololo);
    }
  wololo[pos[0].x + pos[0].y * pix->clipable.buffer.width] = *color;
}
