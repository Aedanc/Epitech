/*
** new_mountain_scroll.c for  in /home/anthony/documents/repository/gfx_scroller/scroll
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sun Mar 20 11:13:59 2016 anthony
** Last update Sun Mar 20 11:25:04 2016 anthony
*/

#include		"scroll.h"

t_info_scroll		*new_mountain_scroll(const char *path,
					     t_info_scroll *init,
					     t_speed speed)
{
  init->pic = bunny_load_picture(path);
  if (init->pic == NULL)
    return (NULL);
  init->blit_1.x = 0;
  init->blit_1.y = WIN_Y_VGA - init->pic->clip_height;
  init->blit_2.x = init->blit_1.x;
  init->blit_2.y = init->blit_1.y;
  init->bgrd_speed = speed;
  init->i = 0;
  return (init);
}
