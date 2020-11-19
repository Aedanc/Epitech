/*
** is_pallette.c for is_pallette in /home/baldas/Prog/repos/info/gfx_tekpaint/src/tmp
**
** Made by baldas
** Login   <baldas@epitech.net>
**
** Started on  Tue Jan 26 16:44:33 2016 baldas
** Last update Tue Jan 26 21:46:46 2016 baldas
*/

#include	<lapin.h>
#include	"../../include/paint.h"

void		is_pallette(t_data *my_data, const t_bunny_position *pos)
{
  t_color	*pixel;

  if ((pos->x > 960 && pos->x < my_data->pix->clipable.clip_width)
      && (pos->y > 68 && pos->y < my_data->pix->clipable.clip_height))
    {
      pixel = (t_color *)my_data->pix->pixels;
      if (pixel[pos->y * my_data->pix->clipable.clip_width
		+ pos->x].full != 0xff8d8d8d)
	my_data->color = pixel[pos->y *
			       my_data->pix->clipable.clip_width + pos->x];
    }
}
