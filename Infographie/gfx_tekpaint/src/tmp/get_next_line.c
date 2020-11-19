/*
** get_next_line.c for  in /home/hurlu/rendu/CPE_2015_getnextline
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Fri Jan  8 18:48:09 2016 Hugo Willaume
** Last update Tue Jan 26 22:54:23 2016 Hugo Willaume
*/

#include <unistd.h>
#include <stdlib.h>
#include <lapin.h>
#include "../../include/get_next_line.h"

void	init_str(char *str, int size)
{
  int	i;

  i = 0;
  while (i <= size)
    {
      str[i] = 0;
      i++;
    }
}

char	*my_re_alloc(char *result, int *malloc_size)
{
  char	*tmp;
  int	i;

  i = 0;
  (*malloc_size) += (*malloc_size);
  if ((tmp = bunny_malloc(sizeof(char *) * (*malloc_size))) == NULL)
    return (NULL);
  init_str(tmp, (*malloc_size));
  while (result[i] != 0)
    {
      tmp[i] = result[i];
      i++;
    }
  i = 0;
  bunny_free(result);
  if ((result = bunny_malloc(sizeof(char *) * (*malloc_size))) == NULL)
    return (NULL);
  init_str(result, (*malloc_size));
  while (tmp[i] != 0)
    {
      result[i] = tmp[i];
      i++;
    }
  bunny_free(tmp);
  return (result);
}

int	init_all(char **buf, char **result, int *y, int *malloc_size)
{
  if (*buf == NULL)
    {
      if ((*buf = bunny_malloc(sizeof(char *) * READ_SIZE)) == NULL)
	return (-1);
      init_str((*buf), READ_SIZE);
    }
  if ((*result = bunny_malloc(sizeof(char *) * READ_SIZE)) == NULL)
    return (-1);
  init_str((*result), READ_SIZE);
  *y = 0;
  *malloc_size = READ_SIZE;
  return (0);
}

int	check_buf(char *buf, int *i, int fd, int *end)
{
  if (buf[(*i)] == 0)
    {
      init_str(buf, READ_SIZE);
      if ((*end = read(fd, buf, READ_SIZE)) < 0)
	return (-1) ;
      *i = 0;
    }
  return (0);
}

char		*get_next_line(const int fd)
{
  static char	*buf;
  static int	i = 0;
  static int	end = 42;
  char		*result;
  int		y;
  int		malloc_size;

  if (init_all(&buf, &result, &y, &malloc_size) != 0)
    return (NULL);
  while (end != 0)
    {
      if (check_buf(buf, &i, fd, &end) != 0)
	return (NULL);
      if (y == malloc_size)
	if ((result = my_re_alloc(result, &malloc_size)) == NULL)
	  return (NULL);
      result[y++] = (buf[i] != '\n' && buf[i] != 0) ? buf[i] : result[y];
      if (buf[i++] == '\n')
	return (result);
    }
  if (result[0] != 0 && i != 0)
    return (result);
  bunny_free(result);
  bunny_free(buf);
  return (NULL);
}
