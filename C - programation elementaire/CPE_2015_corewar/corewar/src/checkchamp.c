/*
** checkchamp.c for  in /home/fortevg/rendu/CPE/CPE_2015_corewar/VM/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Mar 24 01:06:50 2016 Forteville Gabriel
** Last update Sun Mar 27 17:16:00 2016 Hugo Willaume
*/

#include	<stdlib.h>
#include	"op.h"
#include	"virtual.h"

static	int	count_live(t_champions *champ)
{
  int		counter;

  counter = 0;
  while (champ->next != NULL)
    {
      counter += champ->live;
      champ = champ->next;
    }
  return (counter);
}

static void	cmon_die(t_champions *tmpchamp,
			 t_champions *to_delete,
			 t_champions **champ,
			 t_arena *arena)
{
  while (tmpchamp != NULL)
    {
      if (tmpchamp->next != NULL && tmpchamp->live == 1 &&
	  tmpchamp->ch_nb == arena->last_living)
	{
	  to_delete = tmpchamp;
	  tmpchamp->next = tmpchamp->next->next;
	  freechamp(to_delete, champ);
	}
    else if (tmpchamp->next != NULL && tmpchamp->next->live == 0 &&
	  tmpchamp->next->ch_nb != arena->last_living)
	{
	  to_delete = tmpchamp->next;
	  tmpchamp->next = tmpchamp->next->next;
	  freechamp(to_delete, champ);
	}
      else
	{
	  tmpchamp->live = 0;
	  tmpchamp = tmpchamp->next;
	}
    }
}

int		checkchamp(t_champions **champ,
			   t_arena *arena,
			   int check)
{
  t_champions	*tmpchamp;
  t_champions	*to_delete;

  to_delete = NULL;
  tmpchamp = (*champ);
  if (check == TO_KILL)
    {
      while ((*champ) != NULL && (*champ)->next != NULL && (*champ)->live == 0)
	{
	  if (tmpchamp->ch_nb != arena->last_living)
	    freechamp(tmpchamp, champ);
	  (*champ) = (*champ)->next;
	  tmpchamp = (*champ);
	}
      cmon_die(tmpchamp, to_delete, champ, arena);
    }
  else
    check = count_live(tmpchamp);
  return (check);
}
