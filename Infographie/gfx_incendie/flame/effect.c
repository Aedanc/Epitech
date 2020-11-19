/*
** effect.c for  in /home/fortevg/rendu/infographie/gfx_incendie/flame
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sun Dec  6 16:35:37 2015 Forteville Gabriel
** Last update Sun Dec  6 17:06:13 2015 Forteville Gabriel
*/

#include "lapin.h"
#include "flame.h"

void		effect4(t_bunny_pixelarray *pix, t_bunny_position *pos1, t_color color)
{
  int		random;
  int		tmpx;

  pos1->y = 0;
  pos1->x = 0;
  tmpx = pos1->x;
  while (pos1->y < 450)
    {
      random = rand() % 600;
      pos1->x = 0;
      while (pos1->x++ <= tmpx + random )
	tekpixel(pix, pos1, color);
      pos1->x = pos1->x - random;
      pos1->y++;
    }
  pos1->y = 0;
  pos1->x = 0;
  while (pos1->y++ < 450 )
    {
      random = rand() % 600;
      pos1->x = 800;
      while (pos1->x-- >= 800 - random)
	tekpixel(pix, pos1, color);
      pos1->x = pos1->x + random;
    }
}

void		effect3(t_bunny_pixelarray *pix, t_bunny_position *pos1, t_color color)
{
  int		random;
  int		tmpx;

  pos1->y = 0;
  pos1->x = 0;
  tmpx = pos1->x;
  while (pos1->y < 800)
    {
      random = rand() % 100;
      pos1->x = 0;
      while (pos1->x++ <= tmpx + random )
	tekpixel(pix, pos1, color);
      pos1->x = pos1->x - random;
      pos1->y++;
    }
  pos1->y = 0;
  pos1->x = 0;
  while (pos1->y++ < 800 )
    {
      random = rand() % 100;
      pos1->x = 800;
      while (pos1->x-- >= 800 - random)
	tekpixel(pix, pos1, color);
      pos1->x = pos1->x + random;
    }
}

void		effect2(t_bunny_pixelarray *pix, t_bunny_position *pos1, t_color color)
{
  int		random;
  int		tmpx;

  pos1->y = 0;
  pos1->x = 0;
  tmpx = pos1->x;
  while (pos1->y < 700)
    {
      random = rand() % 300;
      pos1->x = 0;
      while (pos1->x++ <= tmpx + random )
	tekpixel(pix, pos1, color);
      pos1->x = pos1->x - random;
      pos1->y++;
    }
  pos1->y = 0;
  pos1->x = 0;
  while (pos1->y++ < 700)
    {
      random = rand() % 300;
      pos1->x = 800;
      while (pos1->x-- >= 800 - random)
	tekpixel(pix, pos1, color);
      pos1->x = pos1->x + random;
    }
}

void		effect1(t_bunny_pixelarray *pix, t_bunny_position *pos1, t_color color)
{
  int		random;
  int		tmpx;

  pos1->y = 0;
  pos1->x = 0;
  tmpx = pos1->x;
  while (pos1->y < 500)
    {
      random = rand() % 400;
      pos1->x = 0;
      while (pos1->x++ <= tmpx + random )
	tekpixel(pix, pos1, color);
      pos1->x = pos1->x - random;
      pos1->y++;
    }
  pos1->y = 0;
  pos1->x = 0;
  while (pos1->y++ < 500)
    {
      random = rand() % 400;
      pos1->x = 800;
      while (pos1->x-- >= 800 - random)
	tekpixel(pix, pos1, color);
      pos1->x = pos1->x + random;
    }
}
