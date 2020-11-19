/*
** tekstretch.c for  in /home/hurlu/rendu/stretcher_2020
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Jan 26 19:08:42 2016 Hugo Willaume
** Last update Tue Jan 26 23:28:06 2016 Hugo Willaume
*/

#include <lapin.h>
#include "../../include/paint.h"

void			init_pos(t_bunny_position *pixpos,
				 int *i, int *y)
{
  pixpos->x = 0;
  pixpos->y = 0;
  *i = -1;
  *y = -1;
}

void			init_ratio(t_bunny_pixelarray *pix, t_bunny_pixelarray *ori,
				   double *ratiowidth, double *ratioheight)
{
  *ratiowidth = (double)(ori->clipable.buffer.width) /
    (double)(pix->clipable.buffer.width);
  *ratioheight = (double)(ori->clipable.buffer.height) /
    (double)(pix->clipable.buffer.height);
}

void			stretch(t_bunny_pixelarray *pix,
				t_bunny_pixelarray *ori)
{
  t_bunny_position	pixpos[1];
  double		ratioheight;
  double		ratiowidth;
  int			i;
  int			y;
  t_color		*my_pix;
  t_color		*ori_pix;

  my_pix = (t_color *)pix->pixels;
  ori_pix = (t_color *)ori->pixels;
  init_pos(pixpos, &i, &y);
  init_ratio(pix, ori, &ratioheight, &ratiowidth);
  while (++i < pix->clipable.buffer.height)
    {
      while (++y < pix->clipable.buffer.width)
	{
	  pixpos->x = (int)(y * ratiowidth) ;
	  pixpos->y = (int)(i * ratioheight) ;
	  my_pix[(i * pix->clipable.buffer.width) + y] =
	    ori_pix[(int)(pixpos->y * ori->clipable.buffer.width) + pixpos->x];
	}
      y = -1;
    }
}
