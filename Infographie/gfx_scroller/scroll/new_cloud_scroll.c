/*
** new_cloud_scroll.c for  in /home/anthony/documents/repository/gfx_scroller/scroll
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sun Mar 20 10:32:54 2016 anthony
** Last update Sun Mar 20 11:13:50 2016 anthony
*/

#include		"scroll.h"

t_info_scroll		*new_cloud_scrolling(const char	*path,
					     t_info_scroll *infos,
					     t_speed speed)
{
  infos->pic = bunny_load_picture(path);
  if (infos->pic == NULL)
    return (NULL);
  infos->blit_1.x = 0;
  infos->blit_1.y = 0;
  infos->blit_2.x = infos->blit_1.x;
  infos->blit_2.y = infos->blit_1.y;
  infos->bgrd_speed = speed;
  infos->i = 0;
  return (infos);
}
