/*
** my_putnbr.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM/src/basics
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Mar 22 13:43:31 2016 Hugo Willaume
** Last update Sun Mar 27 05:38:10 2016 Hugo Willaume
*/

#include	<basics.h>

int	nbnotzero(int nb)
{
  int	tamp;

  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  if (nb > 0)
    {
      tamp = nb;
      nb = nb / 10;
      nbnotzero(nb);
      my_putchar(tamp % 10 + '0');
    }
  return (0);
}

int	my_putnbr(int nb)
{
  if (nb == 0)
    my_putchar('0');
  else
    nbnotzero(nb);
  return (0);
}
