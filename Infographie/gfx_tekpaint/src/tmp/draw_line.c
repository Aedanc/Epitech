/*
** draw_line.c for draw_line in /home/baldas/Prog/repos/info/gfx_tekpaint/src/tmp
**
** Made by baldas
** Login   <baldas@epitech.net>
**
** Started on  Tue Jan 26 21:07:03 2016 baldas
** Last update Thu Jan 28 15:09:48 2016 baldas
*/

#include			<lapin.h>
#include			"../../include/paint.h"
#include			"../../include/basics.h"

void				draw_line(t_data *my_data)
{
  const t_bunny_position	*mouse_pos;
  const bool			*bools;
  t_bunny_position		pos;

  bools = bunny_get_mouse_button();
  mouse_pos = bunny_get_mouse_position();
  pos.x = mouse_pos->x;
  pos.y = mouse_pos->y;
  if (bools[0] == 1)
    {
      if (pos.x >= 90 && pos.y >= 68 &&
	  pos.x <= 941 && pos.y <= 768 && my_data->line.i <= 1)
	{
	  pos.x -= 90;
	  pos.y -= 68;
	  my_data->line.points[my_data->line.i].x = pos.x;
	  my_data->line.points[my_data->line.i].y = pos.y;
	  my_data->line.i++;
	}
      if (my_data->line.i == 2)
	{
	  my_data->line.i = 0;
	  tekline(my_data->draw, my_data->line.points, &my_data->color);
	}
    }
}
