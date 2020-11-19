/*
** my_put_nbr.c for my_put_nbr in /home/fortev_g/daywork/piscine_j07/library
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Tue Oct  6 09:53:41 2015 Gabriel Forteille
** Last update Sun Mar 27 05:39:33 2016 Hugo Willaume
*/

#include	"basics.h"

void	my_putnbrhexspe(int nb, char *base)
{
  if (nb < 16)
    {
      my_putchar('0');
      my_putchar(base[nb]);
      return ;
    }
  my_putchar(base[nb / 16]);
  my_putchar(base[nb % 16]);

}

static void	nbnotzero(int nb)
{
  int		tmp;
  char		*base;

  base = "0123456789ABCDEF";
  if (nb > 0)
    {
      tmp = nb;
      nb /= 16;
      nbnotzero(nb);
      my_putchar(base[tmp % 16]);
      return ;
    }
}

void	my_putnbrhex(int nb)
{
  if (nb == 0)
    my_putchar('0');
  else
    nbnotzero(nb);
}
