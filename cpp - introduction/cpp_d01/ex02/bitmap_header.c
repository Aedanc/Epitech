/*
** bitmap_header.c for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d01/ex03
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Jan 04 18:26:28 2017 Forteville Gabriel
** Last update Thu Jan 05 11:25:41 2017 Forteville Gabriel
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "bitmap.h"

void		make_bmp_header(t_bmp_header *header, size_t size)
{
  header->magic = 0x4D42;
  header->_app1 = 0;
  header->_app2 = 0;
  header->offset = sizeof(t_bmp_header) + sizeof(t_bmp_info_header);
  header->size = header->offset + (size * size * 4);
}


void 		make_bmp_info_header (t_bmp_info_header *header, size_t size)
{
  header->size = 40;
  header->width = size;
  header->height = size;
  header->planes = 1;
  header->bpp = 32;
  header->compression = 0;
  header->raw_data_size = size * size * 4;
  header->h_resolution = 0;
  header->v_resolution = 0;
  header->palette_size = 0;
  header->important_colors = 0;
}
