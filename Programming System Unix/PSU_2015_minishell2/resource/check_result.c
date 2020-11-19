/*
** check_result.c for PSU_2015_minishell2 in /home/fortevg/rendu/PSU/PSU_2015_minishell2/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed May 11 15:46:49 2016 Forteville Gabriel
** Last update Wed May 11 16:05:44 2016 Forteville Gabriel
*/

#include	"minishell.h"

void		check_result(int result)
{
  if (result == 13)
    my_puterror("Command in pipe not found");
}
