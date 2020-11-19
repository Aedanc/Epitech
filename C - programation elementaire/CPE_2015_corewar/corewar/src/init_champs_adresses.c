/*
** init_champs_adresses.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Thu Mar 24 16:29:09 2016 Hugo Willaume
** Last update Sun Mar 27 05:34:59 2016 Hugo Willaume
*/

#include	<stdlib.h>
#include	"virtual.h"
#include	"basics.h"

char		*check_overwrite(t_champions *allch,
				 int actupos)
{
  static char	*last_erased = NULL;
  t_champions	*tmp;

  tmp = allch;
  while (tmp != NULL)
    {
      if (tmp->start_address >= MEM_SIZE)
	{
	  if (tmp->start_address - MEM_SIZE <= actupos &&
	      tmp->start_address
	      - MEM_SIZE + tmp->header->prog_size >= actupos
	      && my_strcmp(last_erased, tmp->header->prog_name) != 0)
	    {
	      last_erased = tmp->header->prog_name;
	      return (last_erased);
	    }
	}
      tmp = tmp->next;
    }
  return (NULL);
}

static void	set_champ(t_champions *champ, t_champions *allch,
			  t_arena *arena)
{
  int		i;
  int		u;
  int		warning;
  char		*erased;

  u = 0;
  i = champ->start_address;
  warning = 0;
  while (u < champ->header->prog_size)
    {
      if ((erased = check_overwrite(allch, i)) != NULL)
	{
	  my_putstr(champ->header->prog_name);
	  my_putstr(" is erasing parts of ");
	  my_putstr(erased);
	  my_putstr(" before the game even beginned! \n");
	  warning++;
	}
      arena->arena[i] = champ->bytecode[u];
      u++;
      i = (i + 1) % MEM_SIZE;
    }
}

int		place_existant_champs(t_champions *champs, t_arena *arena)
{
  t_champions	*tmp;

  tmp = champs;
  while (tmp != NULL)
    {
      if (tmp->start_address < MEM_SIZE)
	set_champ(tmp, champs, arena);
      tmp = tmp->next;
    }
  return (0);
}

int		check_overlap_classic(t_champions *champs)
{
  t_champions	*tmp;
  int		size;

  tmp = champs;
  size = 0;
  while (tmp != NULL)
    {
      size += tmp->header->prog_size;
      tmp = tmp->next;
    }
  if (size > MEM_SIZE)
    return (1);
  return (0);
}

int	champ_adresses(t_champions *champs, t_arena *arena)
{
  if (check_overlap_classic(champs) != 0)
    return (3);
  place_default_champs(champs, arena);
  place_existant_champs(champs, arena);
  return (0);
}
