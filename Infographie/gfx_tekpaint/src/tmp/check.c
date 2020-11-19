/*
** check.c for check in /home/fortevg/rendu/infographie/gfx_tekpaint/src/tmp
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 26 18:53:02 2016 Forteville Gabriel
** Last update Tue Jan 26 19:13:09 2016 Forteville Gabriel
*/

#include			<lapin.h>
#include			"../../include/paint.h"

int				check(void *data)
{
  const bool			*bools;
  const t_bunny_position	*mouse_pos;
  t_data			*my_data;

  bools = bunny_get_mouse_button();
  mouse_pos = bunny_get_mouse_position();
  my_data = data;
  if (bools[0] == 1 && mouse_pos->x >= 90 && mouse_pos->y >= 68 &&
      mouse_pos->y <= 768 && mouse_pos->x <= 941)
    {
      bucket(my_data);
      return (1);
    }
  return (0);
}
