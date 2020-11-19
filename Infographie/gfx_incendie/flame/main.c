/*
** main.c for  in /home/fortevg/rendu/infographi/gfx_incendie/flame
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sat Dec  5 14:03:43 2015 Forteville Gabriel
** Last update Sun Dec  6 18:48:28 2015 Forteville Gabriel
*/

#include <lapin.h>
#include "flame.h"

void		calleffect(t_bunny_pixelarray *pix, t_bunny_position *pos1, t_color color)
{
  color.argb[0] = 0;
  color.argb[1] = 0;
  color.argb[2] = 0;
  effect1(pix, pos1, color);
  effect2(pix, pos1, color);
  effect3(pix, pos1, color);
  effect4(pix, pos1, color);
}

void		color1(t_bunny_pixelarray *pix, t_bunny_position *pos1, t_color color)
{
  while (pos1->y != 785)
    {
      while (pos1->x != 800)
	{
	  tekpixel(pix, pos1, color);
	  pos1->x++;
	}
      if ( pos1->y % 2 == 0)
	color.argb[1]++;
      pos1->x = 0;
      pos1->y++;
    }
  while (pos1->y != 800)
    {
      while (pos1->x != 800)
	{
	  tekpixel(pix, pos1, color);
	  pos1->x++;
	}
      pos1->x = 0;
      pos1->y++;
    }
  calleffect(pix, pos1, color);
  random(pix, pos1, color, 5000);
}

t_bunny_response mainloop(void *p)
{
  t_prog	*prog;
  t_color	color;

  prog = p;
  prog->pos1.x = 0;
  prog->pos1.y = 290;
  color.argb[0] = 255;
  color.argb[1] = 0;
  color.argb[2] = 0;
  color1(prog->pix, &prog->pos1, color);
  prog->pos1.x = 0;
  prog->pos1.y = 0;
  bunny_blit(&prog->win->buffer, &prog->pix->clipable, &prog->pos1);
  bunny_display(prog->win);
  return (GO_ON);
}


int			main()
{
  t_prog		prog;

  prog.win = bunny_start(800, 800, false, "teste");
  prog.pix = bunny_new_pixelarray(800, 800);
  prog.pix->clipable.clip_x_position = 0;
  prog.pix->clipable.clip_y_position = 0;
  prog.pix->clipable.clip_width = 800;
  prog.pix->clipable.clip_height = 800;
  prog.pos1.x = 0;
  prog.pos1.y = 0;
  bunny_set_loop_main_function(mainloop);
  bunny_loop(prog.win, 10, &prog);
  bunny_stop(prog.win);
  return (0);
}
