/*
** flame.h for  in /home/fortevg/rendu/infographi/gfx_incendie/flame
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sat Dec  5 14:01:12 2015 Forteville Gabriel
** Last update Sun Dec  6 16:56:18 2015 Forteville Gabriel
*/

#include "lapin.h"

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos, t_color color);

void		tekcourbe(t_bunny_pixelarray *pix, t_bunny_position *pos,
			  double radius, t_color color);

void		random(t_bunny_pixelarray *pix, t_bunny_position *pos,
		       t_color color, int i);

void		effect1(t_bunny_pixelarray *pix, t_bunny_position *pos1, t_color color);

void		effect2(t_bunny_pixelarray *pix, t_bunny_position *pos1, t_color color);

void		effect3(t_bunny_pixelarray *pix, t_bunny_position *pos1, t_color color);

  void		effect4(t_bunny_pixelarray *pix, t_bunny_position *pos1, t_color color);

typedef struct
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos1;
}			t_prog;
