/*
** scroll.c for  in /home/anthony/documents/repository/gfx_scroller/scroll
**
** Made by anthony
** Login   <anthony@epitech.net>
**
** Started on  Sat Mar 19 15:25:33 2016 anthony
** Last update Sun Mar 20 23:02:16 2016 anthony
*/

#include	       <stdio.h>
#include	       "scroll.h"

void			*init_scroll(t_bunny_window *win)
{
  t_scroll		*init;
  t_bunny_position	text;

  text.x = 0;
  text.y = WIN_Y_VGA - 120;
  if ((init = malloc(sizeof(t_scroll))) == NULL)
    {
      fprintf(stderr, "Malloc error : init_scroll\n");
      return (NULL);
    }
  if ((init->music = init_sampler(win)) == NULL)
    return (NULL);
  init->win = win;
  init->count_speed = 0;
  if (new_cloud_scrolling(PATH_CLOUD_1, &init->bgrd[BG_CLOUDS], SLOW) == NULL)
    return (NULL);
  if (new_mountain_scroll(PATH_MOUNT, &init->bgrd[BG_MOUNTAIN], SSLOW) == NULL)
    return (NULL);
  if (new_fence_scroll(PATH_FENCE, &init->bgrd[BG_FENCE], MEDIUM) == NULL)
    return (NULL);
  if (new_text_scroll(PATH_FENCE, &init->bgrd[BG_TEXT], MEDIUM, &text) == NULL)
    return (NULL);
  return (init);
}

void			destroy_scroll(void *data)
{
  t_scroll		*scroll;

  scroll = data;
  bunny_delete_clipable(scroll->bgrd[BG_CLOUDS].pic);
  bunny_delete_clipable(scroll->bgrd[BG_MOUNTAIN].pic);
  bunny_delete_clipable(scroll->bgrd[BG_FENCE].pic);
  bunny_delete_clipable(scroll->bgrd[BG_TEXT].pic);
  destroy_sampler(scroll->music);
  free(scroll);
}

t_bunny_response	scroll_loop(void *_p)
{
  t_scroll		*prog;
  int			i;

  prog = _p;
  i = 0;
  while (i < MAX_BGRD)
    {
      scrolling(prog->win, &prog->bgrd[i]);
      i++;
    }
  if (play_sound(prog->music) == 1)
    return (EXIT_ON_ERROR);
  bunny_display(prog->win);
  bunny_clear(&prog->win->buffer, 0xFFC07F10);
  prog->count_speed++;
  if (prog->count_speed == 4000)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}
