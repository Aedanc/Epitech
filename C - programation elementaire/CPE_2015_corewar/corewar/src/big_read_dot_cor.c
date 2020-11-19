/*
** big_read_dot_cor.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Wed Mar 23 11:56:17 2016 Hugo Willaume
** Last update Sun Mar 27 05:30:59 2016 Hugo Willaume
*/

#include	<stdlib.h>
#include	"virtual.h"
#include	"basics.h"

int	check_arguments(char **av, int *u)
{

  (*u) = 1;
  if (av[*(u)] == NULL || my_getnbr(av[*(u)]) < 0)
    return (3);
  (*u)++;
  if (av[*(u)] == NULL)
    return (4);
  if (my_strcmp(av[*(u)], "-n") != 0 && my_strcmp(av[*(u)], "-a") != 0)
    return (0);
  if (my_strcmp(av[*(u)], av[0]) == 0)
    return (5);
  if ((my_strcmp(av[*(u)], "-n") == 0 || my_strcmp(av[*(u)], "-a") == 0)
      && (av[(*u) + 1] == NULL || my_getnbr(av[(*u) + 1]) < 0))
    return (3);
  *(u) += 2;
  if (av[*(u)] == NULL)
    return (4);
  if (my_strcmp(av[*(u)], "-n") == 0 || my_strcmp(av[*(u)], "-a") == 0)
    return (4);
  return (0);
}

int		big_read_cor_file(char **av, int *i,
				  t_champions **champs)
{
  int		errcode;
  int		u;
  int		max;
  t_champions	*tmp;

  u = 0;
  if ((errcode = check_arguments(av, &u)) != 0)
    return (errcode);
  max = u;
  u = 0;
  if ((errcode = read_cor_file(av[max], champs)) != 0)
    return (errcode);
  tmp = *champs;
  while (tmp->next != NULL)
    tmp = tmp->next;
  while (u < max)
    {
      if (my_strcmp(av[u], "-a") == 0)
  	tmp->start_address = my_getnbr(av[u + 1]) % MEM_SIZE;
      else if (my_strcmp(av[u], "-n") == 0)
  	tmp->ch_nb = my_getnbr(av[u + 1]);
      u += 2;
    }
  (*i) += max + 1;
  return (0);
}
