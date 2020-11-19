/*
** my_realloc.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM/src/basics
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Mar 22 16:55:24 2016 Hugo Willaume
** Last update Sun Mar 27 05:40:29 2016 Hugo Willaume
*/

#include	<unistd.h>
#include	<stdlib.h>

char	*my_realloc(char *str, int malloc_size)
{
  char	*retval;
  int	i;

  i = -1;
  if ((retval = malloc(sizeof(char) * malloc_size + 1)) == NULL)
    return (NULL);
  while (str[++i] != 0)
    retval[i] = str[i];
  retval[i] = 0;
  free(str);
  return (retval);
}
