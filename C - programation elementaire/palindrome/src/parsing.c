/*
** parsing.c for palindrome in /home/fortevg/rendu/palindrome/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jun 16 13:00:10 2016 Forteville Gabriel
** Last update Sat Jun 18 13:17:53 2016 Forteville Gabriel
*/

#define			_BSD_SOURCE
#define			_GNU_SOURCE
#include		<unistd.h>
#include		<stdio.h>
#include		<string.h>
#include		<stdlib.h>
#include		"struct.h"
#include		"main.h"
#include		"basic.h"

static void			ini_struct(t_data *opt)
{
  opt->nbr_save = NULL;
  opt->nbr = NULL;
  opt->pal = NULL;
  opt->base = 10;
  opt->imin = 0;
  opt->imax = 100;
}

static char			*is_nbr_str(char *str, char *val, t_data *opt,
					    int check)
{
  int				index;
  char				*for_free;

  for_free = NULL;
  index = 0;
  while (str[index] != 0)
    {
      if (str[index] < '0' || str[index] > '9')
	{
	  fprintf(stderr, "%s", val);
	  error("is not a positive number.", opt);
	}
      index++;
    }
  if (check == 1 && strcmp((for_free = revstr(str)), str) != 0)
    {
      free(for_free);
      error("-p need a palindrome (ex: 363)", opt);
    }
  free(for_free);
  return (strdup(str));
}

static int			is_nbr_int(char *str, char *val, t_data *opt)
{
  int				index;

  index = 0;
  if (str == NULL)
    {
      fprintf(stderr, "%s ", val);
      error("is not a positive number.", opt);
    }
  while (str[index] != 0)
    {
      if (str[index] < '0' || str[index] > '9')
	{
	  fprintf(stderr, "%s ", val);
      	  error("is not a positive number.", opt);
	}
      index++;
    }
  return (atoi(str));
}
static void			check(char flag, t_data *opt)
{
  if (flag == 'h')
    print_usage();
  if (flag == 'b')
    opt->base = is_nbr_int(optarg, "base", opt);
  if (flag == 'x')
    opt->imax = is_nbr_int(optarg, "imax", opt);
  if (flag == 'n')
    opt->imin = is_nbr_int(optarg, "imin", opt);
  if (flag == '?')
    exit (84);
}

void			parsing(int ac, char **av, t_data *opt)
{
  char			flag;

  ini_struct(opt);
  flag = getopt(ac, av, "hn:b:p:imn:ax:");
  if (flag == 'n')
    (opt->nbr = is_nbr_str(optarg, "nbr", opt, 0));
  if (flag == 'p')
    opt->pal = is_nbr_str(optarg, "pal", opt, 1);
  while ((flag = getopt(ac, av, "hn:b:p:imn:ax:")) != -1)
      check(flag, opt);
  if (opt->base > 10)
    error("error: base need to be < 10.", opt);
  if ((opt->nbr == NULL && opt->pal == NULL) ||
      (opt->nbr != NULL && opt->pal != NULL))
    print_usage();
  if (opt->imin > opt->imax)
    error("error: imin can't be < imax.", opt);
}
