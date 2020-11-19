/*
** my_put_nbr.c for my_put_nbr in /home/fortev_g/daywork/piscine_j07/library
** 
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
** 
** Started on  Tue Oct  6 09:53:41 2015 Gabriel Forteille
** Last update Sun Nov 15 22:25:12 2015 Gabriel Forteville
*/

int	my_put_nbr(int nb)
{
  int intbase;

  intbase = my_put_nbr_base(nb, "0123456789");
  return (intbase);
}
