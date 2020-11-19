/*
** get_color.c for get_color in /home/baldas/Prog/repos/info/gfx_tekpaint/src/tmp
**
** Made by baldas
** Login   <baldas@epitech.net>
**
** Started on  Tue Jan 26 20:11:13 2016 baldas
** Last update Tue Jan 26 21:01:46 2016 baldas
*/

#include			<lapin.h>
#include			"../../include/paint.h"

void				get_color(t_data *my_data)
{
  const t_bunny_position	*mouse_pos;
  const bool			*bools;
  t_bunny_position		pos;

  mouse_pos = bunny_get_mouse_position();
  pos.x = mouse_pos->x;
  pos.y = mouse_pos->y;
  bools = bunny_get_mouse_button();
  if (bools[0] == 1)
    {
      if (pos.x >= 90 && pos.y >= 68 &&
	  pos.x <= 941 && pos.y <= 768)
	{
	  pos.x -= 90;
	  pos.y -= 68;
	  my_data->color.full = tekgetpixel(my_data->draw, &pos);
	}
    }
}
