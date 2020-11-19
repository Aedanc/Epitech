/*
** tekalphapixel.c for tekpixel avec transparence in /home/lecler_1/repository/alphachannel_2020
**
** Made by Anthony Leclerc
** Login   <lecler_1@epitech.net>
**
** Started on  Wed Dec 23 13:23:38 2015 Anthony Leclerc
** Last update Sun Mar 20 21:07:36 2016 anthony
*/

#include		"tekpixel.h"

void			tekpixel(t_bunny_pixelarray *pix,
				 const t_bunny_position *pos,
				 const TYPE)
{
  t_color		*pixel;
  int			coord;
  double		alpha_fact;

  alpha_fact = ((double)COL_ALPHA / 255);
  coord = pos->x + pos->y * pix->clipable.clip_width;
  pixel = (t_color *)pix->pixels;
  if (coord < pix->clipable.buffer.width * pix->clipable.buffer.height ||
      coord >= 0)
    {
      OLD_RED = alpha_fact * COL_RED + ((1 - alpha_fact) * OLD_RED);
      OLD_GREEN = alpha_fact * COL_GREEN + ((1 - alpha_fact) * OLD_GREEN);
      OLD_BLUE = alpha_fact * COL_BLUE + ((1 - alpha_fact) * OLD_BLUE);
      OLD_ALPHA = COL_ALPHA;
    }
}
