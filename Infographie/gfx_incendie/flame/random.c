/*
** random.c for  in /home/fortevg/rendu/infographie/gfx_incendie/flame
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sat Dec  5 18:59:50 2015 Forteville Gabriel
** Last update Sun Dec  6 16:32:04 2015 Forteville Gabriel
*/

#include	"lapin.h"
#include	<stdlib.h>
#include	"flame.h"

void		random(t_bunny_pixelarray *pix, t_bunny_position *pos,
		       t_color color, int i)
{
  int		b;
  int		c;

  color.argb[0] = 0;
  color.argb[1] = 0;
  color.argb[2] = 0;
  while (i-- > 0)
    {
      c = 40;
      pos->y = 290 + rand() % 500;
      pos->x = rand() % 800;
      tekpixel(pix, pos, color);
      while (c-- > 0)
	{
	  b = 10;
	  pos->x += c;
	  while (b-- > -6)
	  {
	    pos->y = pos->y - b;
	    tekpixel(pix, pos, color);
	  }
	}
    }
}
