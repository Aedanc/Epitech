/*
** tekpaint.c for tekpaint in /home/baldas/Prog/repos/info/gfx_tekpaint/src/tmp
**
** Made by baldas
** Login   <baldas@epitech.net>
**
** Started on  Tue Jan 26 12:08:49 2016 baldas
** Last update Thu Jan 28 18:42:52 2016 Hugo Willaume
*/

#include			<stdio.h>
#include			<lapin.h>
#include			"../../include/basics.h"
#include			"../../include/paint.h"

void				invert_color(t_bunny_pixelarray *pix);

t_bunny_response		key(t_bunny_event_state		state,
				    t_bunny_keysym		key,
				    void			*data)
{
  t_data			*my_data;

  my_data = data;
  if (state == GO_DOWN && key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  else if (state == GO_DOWN && key == BKS_O)
    set_color(my_data->draw, WHITE);
  else if (state == GO_DOWN && key == BKS_L)
    my_data->tool = DO_LINE;
  else if (state == GO_DOWN && key == BKS_I)
    my_data->tool = DO_INVERT;
  else if (state == GO_DOWN && key == BKS_P)
    my_data->tool = DO_PICK_COLOR;
  else if (state == GO_DOWN && key == BKS_UP && my_data->radius < 50)
    my_data->radius++;
  else if (state == GO_DOWN && key == BKS_DOWN && my_data->radius > 1)
    my_data->radius--;
  return (GO_ON);
}

t_bunny_response		click(t_bunny_event_state	state,
				      t_bunny_mousebutton	button,
				      void			*data)
{
  t_data			*my_data;
  const	t_bunny_position	*mouse_pos;
  int				i;

  i = -1;
  my_data = data;
  mouse_pos = bunny_get_mouse_position();
  if (state == GO_DOWN && button == BMB_LEFT)
    while (++i < 11)
      if (is_button(my_data, mouse_pos, i) == 1)
	my_data->tool = my_data->buttons[i].button;
  if (state == GO_DOWN && button == BMB_LEFT)
    is_pallette(my_data, mouse_pos);
  if (my_data->tool == DO_ERASE)
    my_data->color.full = WHITE;
  if (my_data->tool == DO_DRAW_SML)
    my_data->radius = 3;
  else if (my_data->tool == DO_LINE)
    draw_line(my_data);
  else if (my_data->tool == DO_DRAW_MED || my_data->tool == DO_ERASE)
    my_data->radius = 7;
  else if (my_data->tool == DO_DRAW_BIG)
    my_data->radius = 13;
  return (GO_ON);
}

t_bunny_response		main_loop(void *data)
{
  t_data			*my_data;

  my_data = data;
  if (my_data->tool == DO_DRAW_SML || my_data->tool == DO_DRAW_MED ||
      my_data->tool == DO_DRAW_BIG || my_data->tool == DO_ERASE)
    pencil(data);
  else if (my_data->tool == DO_INVERT)
    {
      invert_color(my_data->draw);
      my_data->tool = 0;
    }
  else if (my_data->tool == DO_PICK_COLOR)
    get_color(my_data);
  else if (my_data->tool == DO_OPEN || my_data->tool == DO_SAVE ||
	   my_data->tool == DO_SAVEAS)
    file_handling(my_data);
  bunny_blit(&my_data->win->buffer, &my_data->pix->clipable, NULL);
  bunny_blit(&my_data->win->buffer, &my_data->draw->clipable, &my_data->pos);
  bunny_display(my_data->win);
  return (GO_ON);
}

int				main(int ac, char **av)
{
  t_data			data;

  data.win = bunny_start(1024, 768, false, "TekPaint");
  data.pix = load_bitmap("./interface.bmp");
  data.draw = (ac == 2) ? load_file(av[1], &data) : data.draw ;
  if (data.draw == NULL || ac == 1)
    {
      data.draw = bunny_new_pixelarray(851, 700);
      set_color(data.draw, WHITE);
    }
  data.pos.x = 90;
  data.pos.y = 68;
  data.line.i = 0;
  get_buttons(&data);
  data.tool = 0;
  data.color.full = BLACK;
  set_max_heap_size(30);
  bunny_set_key_response(key);
  bunny_set_click_response(click);
  bunny_set_loop_main_function(main_loop);
  bunny_loop(data.win, 100, &data);
  bunny_delete_clipable(&data.pix->clipable);
  bunny_delete_clipable(&data.draw->clipable);
  bunny_stop(data.win);
  return (0);
}
