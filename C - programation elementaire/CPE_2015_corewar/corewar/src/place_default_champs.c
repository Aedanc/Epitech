/*
** poschamp.c for  in /home/fortevg/rendu/CPE/CPE_2015_corewar/VM
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Mar 24 21:48:22 2016 Forteville Gabriel
** Last update Sun Mar 27 05:42:39 2016 Hugo Willaume
*/

#include	<stdlib.h>
#include	"op.h"
#include	"basics.h"
#include	"virtual.h"

static void	set_champ(char *bytecode, int champ_pos, t_arena *arena,
			  int prog_size)
{
  int		i;

  i = 0;
  while (i < prog_size)
    {
      arena->arena[champ_pos] = bytecode[i];
      i = (i + 1) % MEM_SIZE;
      champ_pos++;
    }
}

static int	get_offset(t_champions *champ)
{
  t_champions	*tmp;
  int		i;
  int		offset;

  tmp = champ;
  i = 0;
  offset = 0;
  while (tmp != NULL)
    {
      i++;
      offset += tmp->header->prog_size;
      tmp = tmp->next;
    }
  offset = ((MEM_SIZE) - offset) / i;
  return (offset);
}

void		place_default_champs(t_champions *champ, t_arena *coloseum)
{
  t_champions	*tmp;
  int		offset;
  int		champ_pos;

  tmp = champ;
  offset = get_offset(champ);
  champ_pos = 0;
  while (tmp != NULL)
    {
      if (tmp->start_address == -1)
	{
	  set_champ(tmp->bytecode, champ_pos, coloseum,
		    tmp->header->prog_size);
	  tmp->start_address = champ_pos + MEM_SIZE;
	  champ_pos += tmp->header->prog_size + offset;
	}
      tmp = tmp->next;
    }
}
