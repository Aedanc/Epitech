/*
** binarizer_2020.c for  in /home/hurlu/rendu/binarizer_2020
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Dec  8 10:14:33 2015 Hugo Willaume
** Last update Thu Jan 28 18:36:01 2016 Hugo Willaume
*/

#include <lapin.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../include/paint.h"

t_color		*read_32_bits(int i, t_bunny_pixelarray *pix2,
			      int fd, t_head *hed)
{
  unsigned char	charbuf[4];
  t_color	*my_pixels;

  my_pixels = (t_color *)pix2->pixels;
  while (read(fd, charbuf, 4) != 0)
    {
      my_pixels[i].argb[BLUE_CMP] = charbuf[1];
      my_pixels[i].argb[GREEN_CMP] = charbuf[2];
      my_pixels[i].argb[RED_CMP] = charbuf[3];
      my_pixels[i].argb[ALPHA_CMP] = charbuf[0];
      i++;
      if (i % hed ->pixwidth == 0)
	i -= hed-> pixwidth * 2;
    }
  return (my_pixels);
}

t_color		*read_24_bits(int i, t_bunny_pixelarray *pix2,
			      int fd, t_head *hed)
{
  unsigned char	charbuf[3];
  t_color	*my_pixels;

  my_pixels = (t_color *)pix2->pixels;
  while (read(fd, charbuf, 3) != 0)
    {
      my_pixels[i].argb[BLUE_CMP] = charbuf[0];
      my_pixels[i].argb[GREEN_CMP] = charbuf[1];
      my_pixels[i].argb[RED_CMP] = charbuf[2];
      i++;
      if (i % hed->pixwidth == 0)
	i -= hed->pixwidth * 2;
    }
  return (my_pixels);
}

void	configure_head(t_head *hed, int *fd)
{
  char	trash[500];

  read((*fd), hed, 54);
  read((*fd), trash, hed->pix_pos_file - 54);
}

t_bunny_pixelarray	*load_bitmap(char *file)
{
  t_bunny_pixelarray	*pix2;
  int			fd;
  t_color		*my_pixels;
  int			i;
  t_head		*hed;

  hed = bunny_malloc(sizeof(t_head));
  fd = open(file, O_RDONLY);
  configure_head(hed, &fd);
  pix2 = bunny_new_pixelarray(hed->pixwidth, hed->pixheight);
  i = hed->pixwidth * hed->pixheight - hed->pixwidth;
  if ((int)hed->bmp_form[0] == 32)
    my_pixels = read_32_bits(i, pix2, fd, hed);
  else if ((int)hed->bmp_form[0] == 24)
    my_pixels = read_24_bits(i, pix2, fd, hed);
  close(fd);
  bunny_free(hed);
  return (pix2);
}
