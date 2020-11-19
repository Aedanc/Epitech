/*
** tekline.c for  in /home/fortevg
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Dec  1 14:51:01 2015 Forteville Gabriel
** Last update Tue Dec 22 17:33:07 2015 Forteville Gabriel
*/

#include <unistd.h>
#include "lapin.h"
#include "stdio.h"

int			main()
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos1;
  t_color		color;

  win = bunny_start(800, 800, false, "teste");
  pix = bunny_new_pixelarray(800, 800);
  pos1.x = 0;
  pos1.y = 0;
  while (pos1.y != 800)
    {
      while (pos1.x != 800)
	{
	  pos1.x++;
	  tekpixel(pix, &pos1, BLACK);
	}
      pos1.x = 0;
      pos1.y++;
    }
  pos1.x = 100;
  pos1.y = 100;
  color.argb[0] = 255;
  color.argb[1] = 0;
  color.argb[2] = 0;
  color.argb[3] = 255;
  teksetpixel(pix, &pos1, &color);
  pos1.x = 0;
  pos1.y = 0;
  bunny_blit(&win->buffer, &pix->clipable, &pos1);
  bunny_display(win);
  usleep(5000000);
  return (0);
}
