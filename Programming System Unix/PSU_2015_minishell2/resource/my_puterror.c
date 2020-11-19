/*
** my_puterror.c for PSU_2015_minishell2 in /home/fortevg/rendu/PSU/PSU_2015_minishell2/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Apr 25 23:37:22 2016 Forteville Gabriel
** Last update Wed May 11 19:07:55 2016 Forteville Gabriel
*/

#include	<unistd.h>
#include	"minishell.h"

int		my_puterror(char *errorstr)
{
  write(2, errorstr, my_strlen(errorstr));
  return (-1);
}
