/*
** my_intlen.c for  in /home/fortevg/rendu/CPE/CPE_2015_BSQ/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Dec 18 16:53:42 2015 Forteville Gabriel
** Last update Fri Dec 18 17:05:30 2015 Forteville Gabriel
*/

int	my_intlen(int	nbr)
{
  int	i;

  i = 1;
  while (nbr > 9)
    {
      i++;
      nbr = nbr % 10;
    }
  return (i);
}
