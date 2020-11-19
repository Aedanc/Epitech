/*
** zjmp.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM/src/instructions
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Sat Mar 26 21:46:34 2016 Hugo Willaume
** Last update Sun Mar 27 22:05:33 2016 Hugo Willaume
*/

#include        "virtual.h"
#include        "op.h"

void	my_zjmp(t_champions *allchamp,
		t_champions *actualchamp,
		t_arena *arena,
		t_process *actualprocess)
{
  (void)allchamp;
  (void)actualchamp;
  (void)arena;
  actualprocess->pc++;
}
