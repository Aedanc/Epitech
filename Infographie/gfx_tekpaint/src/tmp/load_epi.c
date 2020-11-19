/*
** load_epi.c for  in /home/hurlu/rendu/binarizer_2020
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Jan 26 13:10:51 2016 Hugo Willaume
** Last update Tue Jan 26 22:14:51 2016 Hugo Willaume
*/

#include <lapin.h>
#include <unistd.h>
#include <fcntl.h>
#include "../../include/paint.h"

t_bunny_pixelarray	*load_epixelarray(int fd, t_headepi *head,
						  t_bunny_pixelarray *pix)
{
  t_color		*my_pix;
  unsigned char		charbuf[4];
  int			i;

  i = -1;
  my_pix = (t_color *)pix->pixels;
  while (++i < head->width * head->height)
    {
      read(fd, charbuf, 4);
      my_pix[i].argb[0] = charbuf[0];
      my_pix[i].argb[1] = charbuf[1];
      my_pix[i].argb[2] = charbuf[2];
      my_pix[i].argb[3] = charbuf[3];
    }
  return (pix);
}

t_bunny_pixelarray	*load_epi(char *filename)
{
  t_bunny_pixelarray	*pix;
  t_headepi		*head;
  int			fd;

  fd = open(filename, O_RDONLY);
  head = bunny_malloc(sizeof(t_headepi));
  read(fd, head, 12);
  pix = bunny_new_pixelarray(head->width, head->height);
  pix = load_epixelarray(fd, head, pix);
  bunny_free(head);
  return (pix);
}
