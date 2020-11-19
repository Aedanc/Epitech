/*
** main.c for palindrom in /home/fortevg/rendu/palindrome/src
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Thu Jun 16 11:43:32 2016 Gabriel Forteville
** Last update Sat Jun 18 12:57:33 2016 Forteville Gabriel
*/

#define		_GNU_SOURCE
#include	<stdlib.h>
#include	<string.h>
#include	"struct.h"
#include	"main.h"
#include	"basic.h"

int		main(int ac, char **av)
{
  t_data	opt;

  parsing(ac, av, &opt);
  if (opt.nbr != NULL)
    {
      opt.nbr_save = strdup(opt.nbr);
      find_palindrom(&opt, 0);
    }
  else
    find_origins(&opt);
  free(opt.nbr);
  free(opt.pal);
  free(opt.nbr_save);
  return (0);
}
