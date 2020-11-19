/*
** my_putstr.c for SBMLparser in /home/fortevg/rendu/SBMLparser/src/basic
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Mon Jun 13 12:03:17 2016 Gabriel Forteville
** Last update Mon Jun 13 15:47:13 2016 Forteville Gabriel
*/

#include	<unistd.h>
#include	"basic.h"

int		my_putstr(int fd, char *str)
{
  if (str == NULL)
    return (0);
  if (write(fd, str, my_strlen(str)) == -1)
    {
      write(2, "errorw with write\n", 18);
      return (1);
    }
  if (fd == 2)
    return (84);
  return (0);
}
