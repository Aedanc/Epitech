/*
** requirement.c for palindrome in /home/fortevg/rendu/palindrome
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Wed Jun 15 21:29:17 2016 Gabriel Forteville
** Last update Sat Jun 18 09:21:15 2016 Gabriel Forteville
*/

int		my_factrec_synthesis(int nb)
{
  if (nb < 0)
    return (0);
  if (nb == 0)
    return (1);
  if (nb > 12)
    return (0);
  if (nb != 1 && nb != 0)
    return (nb *= my_factrec_synthesis(nb - 1));
  return (nb);
}

int		my_squareroot_synthesis(int nb)
{
  int		result;

  result = 0;
  if (nb < 0)
    return (-1);
  while (result * result < nb)
      result++;
  if (result * result  == nb)
    return (result);
  return (-1);
}
