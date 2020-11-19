/*
** cycle.c for  in /home/fortevg/rendu/CPE/CPE_2015_corewar/VM/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Mar 23 22:37:25 2016 Forteville Gabriel
** Last update Sun Mar 27 23:34:22 2016 Hugo Willaume
*/

#include		<stdlib.h>
#include		"op.h"
#include		"virtual.h"

int			do_instruction(t_champions *allchamp,
				       t_champions *act_champ,
				       t_arena *arena,
				       t_process *process)
{
  if (arena->arena[process->pc] > 0 && arena->arena[process->pc] <= 16)
    {
      g_op_tab[arena->arena[process->pc] - 1].fctn_ptr(allchamp, act_champ,
						     arena, process);
      if (process->cycle == 0)
	return (g_op_tab[(arena->arena[process->pc] - 1) % 16].nbr_cycles);
      else if (process->cycle == 1)
	return (0);
    }
  else
    process->pc = (process->pc + 1) % MEM_SIZE;
  return (0);
}

static void		turn(t_champions *champ,
			     t_arena *arena)
{
  t_process		*tmpprocess;
  t_champions		*tmp;

  tmp = champ;
  while (champ != NULL)
    {
      tmpprocess = champ->process;
      while (tmpprocess != NULL)
	{
	  if (tmpprocess->cycle < 2)
	    tmpprocess->cycle = do_instruction(tmp, champ, arena, tmpprocess);
	  else
	    tmpprocess->cycle--;
	  tmpprocess = tmpprocess->next;
	}
      champ = champ->next;
    }
}

void			champs_dying(t_champions **champ,
				     int *counter,
				     t_arena *arena)
{
  checkchamp(champ, arena, TO_KILL);
  (*counter) = 0;
}

static void		init_values(int *cycle_to_die,
				    int *counter_to_die,
				    int	*nbr_live,
				    t_arena *arena)

{
  (*cycle_to_die) = CYCLE_TO_DIE;
  (*counter_to_die) = 0;
  (*nbr_live) = 0;
  arena->current_cycle = 0;
}

int			cycle(t_champions *champ,
			      t_arena *arena)
{
  int			cycle_to_die;
  int			counter_to_die;
  t_champions		*tmpchamp;
  int			nbr_live;

  init_values(&cycle_to_die, &counter_to_die, &nbr_live, arena);
  while (champ != NULL && champ->next != NULL)
    {
      turn((tmpchamp = champ), arena);
      if (counter_to_die == cycle_to_die)
	{
	  nbr_live += checkchamp(&champ, arena, FOR_NBR_LIVE);
	  champs_dying(&champ, &counter_to_die, arena);
	  cycle_to_die = CYCLE_TO_DIE - (CYCLE_DELTA * (nbr_live / NBR_LIVE));
	}
      counter_to_die++;
      if (arena->current_cycle++ == arena->dump[1] && arena->dump[0] == 1)
	dump_arena(arena, champ);
    }
  my_putaction(champ, WIN);
  return (0);
}
