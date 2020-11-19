/*
** is_a_label.c for is_a_label in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas_h@epitech.net>
**
** Started on  Thu Mar 17 22:29:40 2016 Hugo Baldassin
** Last update Thu Mar 24 01:49:29 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"op.h"
#include	"asm.h"
#include	"my.h"

int		is_a_label_char(char c)
{
  int		i;

  i = 0;
  while (i <= 36)
    {
      if (c == LABEL_CHARS[i])
	return (1);
      i++;
    }
  return (0);
}

int		is_a_direct_label(char *arg, int y)
{
  int		i;

  i = 2;
  if (my_strlen(arg) < 3 || arg[1] != LABEL_CHAR)
    return (0);
  while (arg[i] != '\0')
    {
      if (is_a_label_char(arg[i]) == 0)
	error_displays(-1, y);
      i++;
    }
  return (1);
}

int		is_a_simple_label(char *arg)
{
  int		i;

  i = 0;
  while (arg[i] != LABEL_CHAR && arg[i] != '\0')
    {
      if (is_a_label_char(arg[i]) == 0)
	return (0);
      i++;
    }
  if (arg[i] == '\0')
    return (0);
  else if (arg[i] == LABEL_CHAR && (arg[i + 1] != '\0' || i == 0))
    return (0);
  return (1);
}

int		is_a_label(char *arg, int y)
{
  if (arg[0] == DIRECT_CHAR)
    return (is_a_direct_label(arg, y));
  else
    return (is_a_simple_label(arg));
  return (0);
}
