/*
** save_epi.c for  in /home/hurlu/rendu/binarizer_2020
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Jan 26 13:11:16 2016 Hugo Willaume
** Last update Tue Jan 26 22:15:07 2016 Hugo Willaume
*/

#include <lapin.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../../include/paint.h"

void	configure_epi_head(t_bunny_pixelarray *pix,
			   t_headepi *head)
{
  head->magic_num[0] = 'E';
  head->magic_num[1] = 'P';
  head->magic_num[2] = 'I';
  head->unused = 0;
  head->height = pix->clipable.buffer.height;
  head->width = pix->clipable.buffer.width;
}

void		write_epixarray(int fd, t_bunny_pixelarray *pix,
			t_headepi *head)
{
  int		i;
  t_color	*my_pix;

  i = -1;
  my_pix = (t_color *)pix->pixels;
  while (++i < head->width * head->height)
    write(fd, &my_pix[i].full, 4);
}

void	save_epi(char *filename,
		 t_bunny_pixelarray *pix)
{
  t_headepi	*head;
  int		fd;

  fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
  head = bunny_malloc(sizeof(t_headepi));
  configure_epi_head(pix, head);
  write(fd, head, 12);
  write_epixarray(fd, pix, head);
  bunny_free(head);
}
