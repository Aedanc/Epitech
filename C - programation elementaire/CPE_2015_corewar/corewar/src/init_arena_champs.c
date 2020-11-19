/*
** init_arena_champs.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Wed Mar 23 17:54:22 2016 Hugo Willaume
** Last update Sun Mar 27 23:08:23 2016 Hugo Willaume
*/

#include	<stdlib.h>
#include	"virtual.h"
#include	"basics.h"

static int	scan_errors(int error)
{
  if (error == 1)
    my_putstr("There should be between 2 or 4 champions, no more, no less!\n");
  else if (error == 2)
    my_putstr("You can't have multiple programs with the same number!\n");
  else if (error == 3)
    my_putstr("Champions too big / placed badly: they are overlapping!\n");
  my_putstr("HELP : corewar [-dump nbr_cycle] [[-n prog_number]\
 [-a load_address ] prog_name] \n");
  return (error);
}

int		init_champs(t_champions *champs, t_arena *arena)
{
  int		errcode;

  if ((errcode = champ_numbers(champs)) != 0)
    return (scan_errors(errcode));
  if ((errcode = champ_adresses(champs, arena)) != 0)
    return (scan_errors(errcode));
  return (0);
}

int		init_champs_and_processes(t_champions *champs, t_arena *arena)
{
  t_champions	*tmp;
  int		errcode;

  tmp = champs;
  if ((errcode = init_champs(champs, arena)) != 0)
    return (errcode);
  while (tmp != NULL)
    {
      if (tmp->start_address >= MEM_SIZE)
	tmp->start_address -= MEM_SIZE;
      tmp->process = malloc(sizeof(t_process));
      init_char_array(tmp->process->regs, REG_NUMBER);
      tmp->process->regs[0] = tmp->ch_nb;
      tmp->process->pc = tmp->start_address;
      tmp->process->cycle = 0;
      tmp->process->carry = 0;
      tmp->process->next = NULL;
      tmp = tmp->next;
    }
  return (0);
}

int		init_arena(t_arena *arena, t_champions *champs)
{
  int		i;
  t_champions	*tmp;

  i = 0;
  while (i < MEM_SIZE)
    arena->arena[i++] = 0;
  arena->current_cycle = 0;
  i = 0;
  tmp = champs;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  arena->champ_numbers = i;
  if (arena->champ_numbers < 2 || arena->champ_numbers > 4)
    return (1);
  return (0);
}

int		init_arena_champs(t_arena *arena, t_champions *champs)
{
  int		errcode;

  if ((errcode = init_arena(arena, champs)) != 0)
    return (scan_errors(errcode));
  if ((errcode = init_champs_and_processes(champs, arena)) != 0)
    return (errcode);
  return (0);
}
