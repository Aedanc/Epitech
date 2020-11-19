 /*
** text.c for  in /home/fortevg/rendu/infographie/testtektext
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Feb 16 14:42:22 2016 Forteville Gabriel
** Last update Sun Feb 28 19:33:22 2016 Forteville Gabriel
*/

#include <lapin.h>
#include <stdio.h>
#include "../include/tekgui.h"

void			letters(t_bunny_pixelarray *out,
				t_bunny_pixelarray *fontpng,
				t_bunny_position *letter,
				char c)
{
  t_bunny_position	tmp;
  t_bunny_position	font;
  t_color		color;

  tmp.y = letter->y;
  font.y = 0;
  while (tmp.y < (letter->y + 7))
    {
      tmp.x = letter->x;
      font.x = c * 5;
      while (tmp.x < (letter->x + 5))
	{
	  if ((color.full = tekgetpixel(fontpng, &font)) == (unsigned)WHITE)
	    tekpixel(out, &tmp, &color);
	  font.x++;
	  tmp.x++;
	}
      font.y++;
      tmp.y++;
    }
}

void			tektext(t_bunny_pixelarray *out,
				const char *str,
				t_bunny_pixelarray *fontpng)
{
  int			i;
  t_bunny_position	letter;

  letter.x = 0;
  letter.y = 0;
  i = 0;
  while (str[i] != 0)
    {
      letters(out, fontpng, &letter, str[i]);
      letter.x += 6;
      i++;
    }
}
