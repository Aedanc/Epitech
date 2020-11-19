/*
** main.c for  in /home/fortevg/rendu/CPE/CPE_2015_BSQ
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Dec 15 11:19:12 2015 Forteville Gabriel
** Last update Sun Dec 20 00:50:08 2015 Forteville Gabriel
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

void		ini(t_list *square)
{
  square->x = 0;
  square->y = 0;
  square->lenghtmap = 0;
  square->size = 0;
  square->sizemax = 0;
  square->xmax = 0;
  square->ymax = 0;
}

int		my_getnbrmodified(int fd)
{
  char	c;
  int	i;

  i = 0;
  read(fd, &c, 1);
  while (c != '\n')
    {
      i = i * 10;
      i += (c - 48);
      read(fd, &c, 1);
    }
  return (i);
}

char		**set_tmp(char *buf, char **map)
{
  int		line;
  int		col;
  int		fi;

  line = 0;
  col = 0;
  fi = 0;
  while (buf[fi] != '\0')
    {
      while (buf[fi] != '\n')
	{
	  map[line][col] = buf[fi];
	  col++;
	  fi++;
	}
      map[line][col] = '\0';
      col = 0;
      line++;
      fi++;
    }
  return (map);
}

char		**malloc_tmp(t_list *square, char *buf, int nbrline)
{
  char		**tmp;

  tmp = malloc((nbrline + 1) * (sizeof(char *)));
  if (tmp == NULL)
    return (NULL);
  while (buf[square->lenghtmap++] != '\n');
  while (nbrline > 0)
    {
      nbrline--;
      tmp[nbrline] = malloc(square->lenghtmap);
      if (tmp[nbrline] == NULL)
	return (NULL);
    }
  return (tmp);
}

int		main(int ac, char **av)
{
  struct stat	plop;
  const char	*pathfile;
  int		fd;
  char		*buf;
  char		**map;
  int		nbrline;
  t_list	square;
  int		ret;

  ini(&square);
  pathfile = av[1];
  fd = open(pathfile, O_RDONLY);
  if (ac != 2 || fd == -1)
    return (0);
  stat(pathfile, &plop);
  buf = malloc(plop.st_size);
  nbrline = my_getnbrmodified(fd);
  ret = read(fd, buf, (plop.st_size - (my_intlen(nbrline) + 1)));
  buf[ret] = '\0';
  map = malloc_tmp(&square, buf, nbrline);
  map = set_tmp(buf, map);
  map = now_find_the_square(&square, map, nbrline);
  now_put_the_square(&square, map);
  close(fd);
  return (0);
}
