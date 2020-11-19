/*
** init_champs.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Wed Mar 23 18:52:05 2016 Hugo Willaume
** Last update Sun Mar 27 05:35:18 2016 Hugo Willaume
*/

#include	<stdlib.h>
#include	"virtual.h"
#include	"basics.h"

static void	set_numbers(int *nb_champs, t_champions *champs)
{
  int		nb;
  t_champions	*tmp;

  nb = 1;
  tmp = champs;
  while (tmp != NULL)
    {
      if (tmp->ch_nb == 0)
  	{
  	  while (is_not_in_i(nb_champs, nb, 4) == 1 || nb == tmp->ch_nb)
  	    nb++;
  	  tmp->ch_nb = nb;
	  nb++;
  	}
      tmp = tmp->next;
    }
}

static int	check_identicals(int *nb_champs)
{
  int	       	i;
  int		y;

  i = 0;
  while (i < 3)
    {
      y = i + 1;
	while (y < 4)
	  {
	    if (nb_champs[i] == nb_champs[y] && nb_champs[i] != 0)
	      return (1);
	    y++;
	  }
      i++;
    }
  return (0);
}

int		champ_numbers(t_champions *champs)
{
  t_champions	*tmp;
  int		nb_champs[4];
  int		i;

  tmp = champs;
  i = 0;
  init_int_array(nb_champs, 4);
  while (tmp != NULL)
    {
      nb_champs[i] = tmp->ch_nb;
      i++;
      tmp = tmp->next;
    }
  if (check_identicals(nb_champs) != 0)
    return (1);
  set_numbers(nb_champs, champs);
  return (0);
}
