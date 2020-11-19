/*
** my_calloc.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Wed Mar 23 14:24:08 2016 Hugo Willaume
** Last update Sun Mar 27 05:38:53 2016 Hugo Willaume
*/

#include	<stdlib.h>

char	*my_calloc(int size)
{
  char	*retval;
  int	i;

  retval = malloc(size + 1);
  i = -1;
  while (++i < size)
    retval[i] = 0;
  return (retval);
}
