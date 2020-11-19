/*
** tektext.h for  in /home/fortevg/rendu/infographie/testtektext
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Feb 16 17:26:07 2016 Forteville Gabriel
** Last update Sun Feb 28 17:51:25 2016 Forteville Gabriel
*/

#ifndef _TEKTEXT_H_
#define  _TEKTEXT_H_

typedef struct
{
  t_bunny_window        *win;
  t_bunny_pixelarray    *pix;
  t_bunny_pixelarray    *font;
  t_bunny_position      pos1;
}                       t_prog;

void                    tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);

unsigned int            tekgetpixel(t_bunny_pixelarray *pix,
				    t_bunny_position *pos);

void			tekletter(t_bunny_pixelarray *pix,
				  char c);

void			tektext(t_bunny_pixelarray *out,
				const char *str,
				t_bunny_pixelarray *fontpng);
#endif
