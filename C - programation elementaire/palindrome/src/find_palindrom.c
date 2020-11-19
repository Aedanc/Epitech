/*
** find_palindrom.c for palindrome in /home/fortevg/rendu/palindrome/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jun 16 16:34:52 2016 Forteville Gabriel
** Last update Sat Jun 18 13:39:52 2016 Forteville Gabriel
*/

#define		_GNU_SOURCE
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"struct.h"
#include	"basic.h"

static int	search_palindrome(t_data *opt, int cpt, char *tmp)
{
  char		*for_free;

  for_free = revstr(opt->nbr);
  tmp = add_str(opt->nbr, for_free);
  free(for_free);
  if (tmp == NULL || (opt->pal != NULL && cpt >= atoi(opt->pal)))
    return (-1) ;
  free(opt->nbr);
  opt->nbr = strdup(tmp);
  free(tmp);
  return (0);
}

void		find_palindrom(t_data *opt, int cpt)
{
  char		*for_free;
  char		*tmp;

  for_free = NULL;
  tmp = NULL;
  while (opt->nbr && ((cpt < opt->imax &&
		       (strcmp(opt->nbr, (for_free = revstr(opt->nbr))) != 0))
		      || cpt < opt->imin))
    {
      free (for_free);
      if (search_palindrome(opt, cpt, tmp) == - 1)
	break;
      cpt++;
    }
  if ((((opt->nbr == NULL || tmp == NULL) && opt->pal == NULL) ||
      cpt == opt->imax) && strcmp(opt->nbr, (for_free = revstr(opt->nbr)))
      != 0)
    {
      free(for_free);
      error("no solution", opt);
    }
  printf("%s leads to %s in %i iteration(s) in base %i\n",
	 opt->nbr_save, opt->nbr, cpt, opt->base);
  free(for_free);
}
