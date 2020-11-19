/*
** pencil.c for pencil in /home/baldas/Prog/repos/info/gfx_tekpaint/src/tmp
**
** Made by baldas
** Login   <baldas@epitech.net>
**
** Started on  Tue Jan 26 14:32:10 2016 baldas
** Last update Tue Jan 26 18:47:39 2016 baldas
*/

#include			<lapin.h>
#include			"../../include/basics.h"
#include			"../../include/paint.h"

void				pencil(void *data)
{
  t_data			*my_data;
  const bool			*bools;
  const t_bunny_position	*mouse_pos;
  double			tmp;
  t_bunny_position		pos;

  my_data = data;
  mouse_pos = bunny_get_mouse_position();
  bools = bunny_get_mouse_button();
  tmp = my_data->radius + 1;
  if (bools[0] == 1 &&
      mouse_pos->x > my_data->pos.x &&
      mouse_pos->y > my_data->pos.y &&
      mouse_pos->x < my_data->pos.x + my_data->draw->clipable.clip_width &&
      mouse_pos->y < my_data->pos.y + my_data->draw->clipable.clip_height)
    {
      pos.x = mouse_pos->x - my_data->pos.x;
      pos.y = mouse_pos->y - my_data->pos.y;
      while (--tmp > 0)
	tekcircle(my_data->draw, &pos,
		  tmp, &my_data->color);
    }
}
