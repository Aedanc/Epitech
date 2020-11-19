/*
** main.c for SBMLparser in /home/fortevg/rendu/SBMLparser
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Last update Tue Jun 14 22:29:18 2016 Forteville Gabriel
** Last update Wed Jun 15 16:22:29 2016 Forteville Gabriel
*/

#define 	_GNU_SOURCE
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"main.h"
#include	"struct.h"
#include	"basic.h"

int		main(int ac, char *av[])
{
  t_data	*info_file;
  char		i_flag;
  char		*path;

  i_flag = 0;
  if (av[1] != NULL)
    path = strdup(av[1]);
  if (ac < 2 || (i_flag = parsing(ac, av)) == -1)
    return (print_usage());
  info_file = get_data_from_file(path);
  if (i_flag != 1)
    print_in_alpha_order(info_file);
  else
    print_species(info_file);
  free_linked_list(info_file);
  free(path);
  return (0);
}
