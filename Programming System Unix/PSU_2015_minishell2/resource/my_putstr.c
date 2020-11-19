/*
** my_putstr.c for  in /home/fortevg/rendu/PSU/PSU_2015_my_select
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Dec  8 12:41:33 2015 Forteville Gabriel
** Last update Fri May  6 14:31:01 2016 Forteville Gabriel
*/

#include	<unistd.h>
#include	"minishell.h"

int		my_putstr(char *str)
{
  return (write(1, str, my_strlen(str)));
}
