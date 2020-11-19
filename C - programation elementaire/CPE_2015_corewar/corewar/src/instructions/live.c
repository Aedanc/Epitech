/*
** live.c for  in /home/fortevg/rendu/CPE/CPE_2015_corewar/VM/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Mar 23 14:03:21 2016 Forteville Gabriel
** Last update Sun Mar 27 21:44:09 2016 Hugo Willaume
*/

#include	<stdlib.h>
#include	"virtual.h"
#include	"op.h"

static void	end_live(t_process *actualprocess,
			 t_champions *allchamp,
			 t_arena *arena)
{
  t_champions	*tmp;

  actualprocess->pc = (actualprocess->pc + 5) % MEM_SIZE;
  tmp = allchamp;
  while (tmp != NULL && tmp->ch_nb != actualprocess->args[0])
    tmp = tmp->next;
  if (tmp != NULL)
    {
      tmp->live++;
      arena->last_living = actualprocess->args[0];
      my_putaction(tmp, LIFE);
    }
  free(actualprocess->args);
}

void		my_live(t_champions *allchamp,
			t_champions *actualchamp,
			t_arena *arena,
			t_process *actualprocess)
{
  int		i;
  t_4chartoint	data;

  (void)actualchamp;
  if (actualprocess->cycle == 0)
    {
      actualprocess->args = malloc(sizeof(int) * 2);
      i = -1;
      while (++i < 4)
	data.opcode[i] = arena->arena[actualprocess->pc + 1 + i];
      actualprocess->args[0] = big_endian(data.nbrread);
    }
  else
    {
      end_live(actualprocess, allchamp, arena);
    }
}
