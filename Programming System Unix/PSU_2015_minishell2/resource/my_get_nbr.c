/*
** my_getnbr.c for fractals in /home/fortevg/rendu/CPE/CPE_colle_semaine2
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed May  4 09:35:20 2016 Forteville Gabriel
** Last update Wed May 11 17:45:18 2016 Forteville Gabriel
*/

#include	"minishell.h"

int		my_get_nbr(char *str, int index)
{
  int		result_nbr;
  bool		is_neg;

  is_neg = FALSE;
  result_nbr = 0;
  if (str[index] == '-')
    {
      is_neg = TRUE;
      index++;
    }
  while (str[index] != 0)
    {
      result_nbr = (result_nbr * 10) + (str[index] - 48);
      index++;
    }
  if (is_neg == TRUE)
    return (-result_nbr);
  return (result_nbr);
}
