/*
** my_strdup.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM/src/basics
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Mar 22 13:37:56 2016 Hugo Willaume
** Last update Sun Mar 27 05:41:14 2016 Hugo Willaume
*/

#include	<stdlib.h>
#include	"basics.h"

char	*my_strdup(char *str)
{
  char	*retval;
  int	i;

  retval = malloc(sizeof(char) * (my_strlen(str) + 1));
  i = 0;
  while (str[i] != 0)
    {
      str[i] = retval[i];
      i++;
    }
  return (retval);
}
