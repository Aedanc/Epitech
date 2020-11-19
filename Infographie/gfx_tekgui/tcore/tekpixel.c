/*
** tekpixel.c for  in /home/fortevg/rendu/infographie/chatty_2020
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Feb 17 09:09:31 2016 Forteville Gabriel
** Last update Sun Feb 28 17:50:59 2016 Forteville Gabriel
*/

#include <lapin.h>
#include "../include/tekgui.h"

void            tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color)
{
  t_color *wololo;

  wololo = pix->pixels;
  if (pos->x < pix->clipable.clip_width && pos->x > 0 &&
      pos->y < pix->clipable.clip_height && pos->y > 0)
    wololo[pos->x + pos->y * pix->clipable.clip_width] = *color;
}
