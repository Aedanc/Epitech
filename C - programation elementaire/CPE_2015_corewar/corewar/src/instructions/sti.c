/*
** sti.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM/src/instructions
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sat Mar 26 21:46:46 2016 Hugo Willaume
** Last update Sun Mar 27 22:52:04 2016 Hugo Willaume
*/

#include	<stdlib.h>
#include	"basics.h"
#include        "virtual.h"
#include        "op.h"

static int	get_ind(int *pos,
			t_arena *arena)
{
 t_2ctos	data;

 data.opcode[0] = arena->arena[(*pos) % MEM_SIZE];
 (*pos)++;
 data.opcode[1] = arena->arena[(*pos) % MEM_SIZE];
 (*pos)++;
 return (data.nbrread);
}

static int	get_reg(int *pos,
			t_arena *arena,
			t_process *actualprocess)
{
  int	reg;

  reg = arena->arena[(*pos) % MEM_SIZE];
  reg = actualprocess->regs[reg % REG_NUMBER];
  (*pos)++;
  return (reg);
}

static void	gather_data(t_process *actualprocess,
			    t_arena *arena)

{
  char		*opcode;
  int		pos;

  pos = actualprocess->pc + 2;
  opcode = readoctecodage(arena, actualprocess);
  if ((actualprocess->args = malloc(sizeof(int) * 3)) == NULL)
    {
      my_putstr("MALLOC ERROR \n");
      exit (1);
    }
  actualprocess->args[1] = 0;
  actualprocess->args[2] = 0;
  actualprocess->args[0] = arena->arena[(actualprocess->pc + 2) % MEM_SIZE];
  if (actualprocess->args[0] < 0)
      return ;
  if (opcode[1] == 2)
    actualprocess->args[2] = get_ind(&pos, arena);
  else
    actualprocess->args[2] = get_reg(&pos, arena, actualprocess);
  if (opcode[2] == 2)
    actualprocess->args[1] = get_ind(&pos, arena);
  else
    actualprocess->args[1] = get_reg(&pos, arena, actualprocess);
  free(opcode);
}

static int	get_size(t_process *actualprocess,
			 t_arena *arena)
{
  char		*opcode;
  int		i;
  int		size;

  size = 2;
  i = 0;
  opcode = readoctecodage(arena, actualprocess);
  while (i < 4)
    {
      if (opcode[i] == 1)
	size += 1;
      else if (opcode[i] == 2)
	size += DIR_SIZE;
      else if (opcode[i] == 3)
	size += IND_SIZE;
      i++;
    }
  free(opcode);
  return (size);
}

void		my_sti(t_champions *allchamp,
		       t_champions *actualchamp,
		       t_arena *arena,
		       t_process *actualprocess)
{
  int		i;
  t_4chartoint	data;

  (void)allchamp;
  (void)actualchamp;
  if (actualprocess->cycle == 0)
    gather_data(actualprocess, arena);
  if (actualprocess->cycle == 1)
    {
      if (actualprocess->args[0] < 0)
	return ;
      data.nbrread = actualprocess->args[0];
      i = actualprocess->args[1] + actualprocess->args[2] - 1;
      while (++i < actualprocess->args[1] + actualprocess->args[2] + 4)
	arena->arena[(actualprocess->pc + i) % MEM_SIZE] = data.opcode
	  [i - actualprocess->args[1] - actualprocess->args[2]];
      actualprocess->pc = (actualprocess->pc + get_size(actualprocess, arena))
	% MEM_SIZE;
      free(actualprocess->args);
    }
}
