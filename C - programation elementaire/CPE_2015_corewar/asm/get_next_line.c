/*
** read_line_and_display_remaining.c for read_line_and_display_remaining in /home/baldas/Prog/repos/PSU/CPE_2015_getnextline_bootstrap
**
** Made by baldas
** Login   <baldas@epitech.net>
**
** Started on  Wed Jan  6 15:14:46 2016 baldas
** Last update Fri Mar 25 18:37:33 2016 vermeu_v
*/

#include <stdlib.h>
#include <unistd.h>
#include "convert.h"

int	line_check(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	return (1);
      i++;
    }
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i++;
  return (i);
}

void	epur(char *line, char *buf)
{
  int	i;
  int	j;
  int	len;

  i = 0;
  j = 0;
  len = my_strlen(line);
  if (line == NULL)
    return ;
  while (line[i] != '\n' && line[i] != '\0')
    i++;
  line[i] = '\0';
  if (i < len)
    {
      i++;
      while (line[i] != '\0')
	buf[j++] = line[i++];
    }
  buf[j] = '\0';
}

char	*my_strcat(char *line, char *buf)
{
  int	i;
  int	j;
  char	*res;

  i = 0;
  j = 0;
  if (!(res = malloc((my_strlen(line) + my_strlen(buf) + 1) * sizeof(char))))
    return (NULL);
  while (line != NULL && line[i] != '\0')
    {
      res[i] = line[i];
      i++;
    }
  while (buf[j] != '\0')
    {
      res[i + j] = buf[j];
      j++;
    }
  res[i + j] = '\0';
  free(line);
  return (res);
}

char		*get_next_line(int fd)
{
  static char	*buf = NULL;
  char		*line;
  int		len;

  if (buf == NULL)
    {
      if (!(buf = malloc((READ_SIZE + 1) * sizeof(char))))
	return (NULL);
      buf[0] = '\0';
    }
  len = 1;
  line = NULL;
  line = my_strcat(line, buf);
  while (line_check(buf) == 0 && len != 0)
    {
      len = read(fd, buf, READ_SIZE);
      if (len == -1)
	return (NULL);
      buf[len] = '\0';
      line = my_strcat(line, buf);
    }
  if (my_strlen(line) == 0)
    line = NULL;
  epur(line, buf);
  return (line);
}
