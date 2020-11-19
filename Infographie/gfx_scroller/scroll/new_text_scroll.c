/*
** new_text_scroll.c for  in /home/anthony/documents/repository/gfx_scroller/scroll
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sun Mar 20 13:16:42 2016 anthony
** Last update Sun Mar 20 23:15:10 2016 anthony
*/

#include		"scroll.h"

t_info_scroll		*new_text_scroll(const char *path,
					 t_info_scroll *init,
					 t_speed speed,
					 const t_bunny_position *space)
{
  (void)path;
  init->pic = scrollingtext("Demo Scroller by : Leclerc A., "
			    "Willaume H. and Forteville G. !");
  if (init->pic == NULL)
    return (NULL);
  init->blit_1.x = space->x;
  init->blit_1.y = space->y;
  init->blit_2.x = init->blit_1.x;
  init->blit_2.y = init->blit_1.y;
  init->bgrd_speed = speed;
  init->i = 0;
  return (init);
}
