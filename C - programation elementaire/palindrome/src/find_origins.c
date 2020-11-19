/*
** find_origin.c for palindrome in /home/fortevg/rendu/palindrome/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jun 17 17:54:58 2016 Forteville Gabriel
** Last update Sat Jun 18 13:36:26 2016 Forteville Gabriel
*/

#define			_GNU_SOURCE
#include		<stdlib.h>
#include		<string.h>
#include		<stdio.h>
#include		"struct.h"
#include		"basic.h"

static int		search_origin(t_data *opt)
{
  char			*for_free;
  char			*tmp;
  int			cpt;

  cpt = 0;
  while (opt->nbr && opt->pal && (atoi(opt->nbr) < atoi(opt->pal)
				  || cpt < opt->imin) && cpt < opt->imax)
    {
      tmp = add_str(opt->nbr, (for_free = revstr(opt->nbr)));
      free(opt->nbr);
      opt->nbr = NULL;
      if (tmp != NULL)
	opt->nbr = strdup(tmp);
      free(tmp);
      free(for_free);
      cpt++;
    }
  if (opt->nbr && opt->pal && atoi(opt->nbr) == atoi(opt->pal))
    {
      printf("%s leads to %s in %i iteration(s) in base %i\n",
	     opt->nbr_save, opt->nbr, cpt, opt->base);
      return (1);
    }
  return (0);
}

void			find_origins(t_data *opt)
{
  int			index;
  int			check;

  check = 0;
  index = 1;
  while (opt->pal && index <= atoi(opt->pal))
    {
      opt->nbr_save = int_to_str(index);
      opt->nbr = int_to_str(index);
      check += search_origin(opt);
      index++;
      free(opt->nbr_save);
      free(opt->nbr);
      opt->nbr_save = NULL;
      opt->nbr = NULL;
    }
  if (check == 0)
    error("no solution", opt);
  opt->nbr_save = NULL;
  opt->nbr = NULL;
}
