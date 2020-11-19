/*
** is_button.c for is_button in /home/baldas/Prog/repos/info/gfx_tekpaint/src/tmp
**
** Made by baldas
** Login   <baldas@epitech.net>
**
** Started on  Tue Jan 26 16:25:55 2016 baldas
** Last update Tue Jan 26 16:34:19 2016 baldas
*/

#include	<lapin.h>
#include	"../../include/paint.h"

int		is_button(t_data			*prog,
			  const t_bunny_position	*pos,
			  int				i)
{
  if (pos->x > prog->buttons[i].pos1.x && pos->x < prog->buttons[i].pos2.x
      && pos->y > prog->buttons[i].pos1.y && pos->y < prog->buttons[i].pos2.y)
    return (1);
  return (0);
}
