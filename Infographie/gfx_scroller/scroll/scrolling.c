/*
** scrolling.c for  in /home/anthony/documents/repository/gfx_scroller/include
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sat Mar 19 18:06:15 2016 anthony
** Last update Sun Mar 20 12:16:21 2016 anthony
*/

#include		"scroll.h"

void			scrolling(t_bunny_window *win,
				  t_info_scroll *prog)
{
  int			clip_width_tmp;
  int			clip_x_pos_tmp;

  bunny_blit(&win->buffer, prog->pic, &prog->blit_1);
  if (prog->pic->clip_x_position > prog->pic->buffer.width - WIN_X_VGA)
    {
      clip_width_tmp = --prog->pic->clip_width;
      clip_x_pos_tmp = ++prog->pic->clip_x_position;
      prog->i += prog->bgrd_speed;
      prog->pic->clip_width = prog->i;
      prog->pic->clip_x_position = 0;
      prog->blit_2.x = WIN_X_VGA - prog->i;
      bunny_blit(&win->buffer, prog->pic, &prog->blit_2);
      prog->pic->clip_width = clip_width_tmp;
      prog->pic->clip_x_position = clip_x_pos_tmp - 1;
    }
  if (prog->pic->clip_x_position >= prog->pic->buffer.width)
    {
      prog->pic->clip_width = WIN_X_VGA;
      prog->pic->clip_x_position = 0;
      prog->i = 0;
    }
  prog->pic->clip_x_position += prog->bgrd_speed;
}
