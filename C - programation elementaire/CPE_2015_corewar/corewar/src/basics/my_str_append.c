/*
** my_str_append.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Wed Mar 23 10:46:52 2016 Hugo Willaume
** Last update Sun Mar 27 05:40:48 2016 Hugo Willaume
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"basics.h"

char	*my_str_append(char *str1, char *append)
{
  char	*retval;
  int	i;
  int	y;

  if (append == NULL)
    return (NULL);
  if (str1 == NULL)
    retval = my_calloc(sizeof(char) * (my_strlen(append) + 1));
  else
    retval = my_calloc(sizeof(char) *
		       (my_strlen(str1) + my_strlen(append) + 1));
  i = -1;
  while (str1[++i] != 0)
    retval[i] = str1[i];
  y = 0;
  while (append != NULL && append[y] != 0)
    {
      retval[i] = append[y];
      i++;
      y++;
    }
  retval[i] = 0;
  free(str1);
  return (retval);
}
