/*
** my_isneg.c for y_isneg in /home/fortev_g/test
** 
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
** 
** Started on  Wed Sep 31 11:36:51 2015 Gabriel Forteville
** Last update Thu Nov  5 10:16:30 2015 Gabriel Forteville
*/
#include "my.h"

int	my_isneg(int nb)
{
  if (nb >= 0)
    {
      my_putchar('P');
    }
  else
    {
      my_putchar('N');
    }
  return (0);
}
