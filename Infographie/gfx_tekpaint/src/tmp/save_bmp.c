/*
** save_bmp.c for  in /home/hurlu/rendu/binarizer_2020
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Fri Jan 22 15:53:14 2016 Hugo Willaume
** Last update Tue Jan 26 22:06:26 2016 Hugo Willaume
*/

#include <lapin.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../../include/paint.h"

void	create_head_from_scratch(t_bunny_pixelarray *pix, t_head *head)
{
  head->magic_num[0] = 'B';
  head->magic_num[1] = 'M';
  head->pix_pos_file = 54;
  head->header_size = 40;
  head->pixwidth = pix->clipable.buffer.width;
  head->pixheight = pix->clipable.buffer.height;
  head->sizefile = head->pix_pos_file+ head->pixwidth * head->pixheight * 3;
  head->unused = 0;
  head->bit_plan[0] = 1;
  head->bit_plan[1] = 0;
  head->bmp_form[0] = 24;
  head->bmp_form[1] = 0;
  head->compression = 0;
  head->pix_size = 0;
  head->res_width = 2348;
  head->res_height = head->res_width;
  head->palet_nb = 0;
  head->master_color = 0;
}

void	create_head_from_old(t_bunny_pixelarray *pix,
			     t_head *head, t_head *oldhead)
{
  head->magic_num[0] = oldhead->magic_num[0];
  head->magic_num[1] = oldhead->magic_num[1];
  head->sizefile = oldhead->sizefile;
  head->unused = oldhead->unused;
  head->pix_pos_file = oldhead->pix_pos_file;
  head->header_size = oldhead->header_size;
  head->pixwidth = pix->clipable.buffer.width;
  head->pixheight = pix->clipable.buffer.height;
  head->bit_plan[1] = 0;
  head->bit_plan[0] = 1;
  head->bmp_form[0] = oldhead->bmp_form[0];
  head->bmp_form[1] = oldhead->bmp_form[1];
  head->compression = 0;
  head->pix_size = oldhead->pix_size;
  head->res_width = oldhead->res_width;
  head->res_height = oldhead->res_height;
  head->palet_nb = oldhead->palet_nb;
  head->master_color = oldhead->master_color;
}

void		write_pixarray_24_bit(int fd, t_head *head,
				      t_bunny_pixelarray *pix)
{
  t_color	*my_pix;
  int		i;
  int		j;

  j = 0;
  my_pix = (t_color *)pix->pixels;
  i = head->pixwidth * head->pixheight - head->pixwidth;
  while (i >= 0)
    {
      write(fd, &my_pix[i].argb[BLUE_CMP], 1);
      write(fd, &my_pix[i].argb[GREEN_CMP], 1);
      write(fd, &my_pix[i].argb[RED_CMP], 1);
      j += 3;
      i++;
      if (i % head->pixwidth == 0)
	{
	  i -= head->pixwidth * 2;
	  while (j % 4 != 0)
	    {
	      write(fd, 0, 1);
	      j++;
	    }
	}
    }
}

void		write_pixarray_32_bit(int fd, t_head *head,
				      t_bunny_pixelarray *pix)
{
  t_color	*my_pix;
  int		i;
  int		j;

  j = 0;
  my_pix = (t_color *)pix->pixels;
  i = head->pixwidth * head->pixheight - head->pixwidth;
  while (i >= 0)
    {
      write(fd, &my_pix[i].argb[BLUE_CMP], 1);
      write(fd, &my_pix[i].argb[GREEN_CMP], 1);
      write(fd, &my_pix[i].argb[RED_CMP], 1);
      write(fd, &my_pix[i].argb[ALPHA_CMP], 1);
      j += 4;
      i++;
      if (i % head->pixwidth == 0)
	i -= head->pixwidth * 2;
    }
}

void	save_bitmap(char *filename, t_bunny_pixelarray *pix,
		    char *oldfilename)
{
  t_head	*head;
  t_head	*oldhead;
  int		fd;

  oldhead = bunny_malloc(sizeof(t_head));
  if (oldfilename != NULL)
    {
      fd = open(oldfilename, O_RDONLY);
      read(fd, oldhead, 54);
      close(fd);
    }
  fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
  head = bunny_malloc(sizeof(t_head));
  if (my_strcmp(oldfilename, "scratch") == 0)
    create_head_from_scratch(pix, head);
  else
    create_head_from_old(pix, head, oldhead);
  write(fd, head, 54);
  write(fd, oldhead, head->pix_pos_file - 54);
  if ((int)head->bmp_form[0] == 32)
    write_pixarray_32_bit(fd, head, pix);
  else if ((int)head->bmp_form[0] == 24)
    write_pixarray_24_bit(fd, head, pix);
  bunny_free(head);
  bunny_free(oldhead);
}
