/*
** tekpixelpropre.c for  in /home/hurlu/rendu/Infographie
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sat Dec  5 11:05:40 2015 Hugo Willaume
** Last update Thu Dec 24 15:42:41 2015 Hugo Willaume
*/

#include	<lapin.h>

void	tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos,
		 t_color *color)
{
  t_color	*my_pix;

  my_pix = (t_color *)pix->pixels;
  my_pix[pos->y * pix->clipable.buffer.width + pos->x] = *color;
}
