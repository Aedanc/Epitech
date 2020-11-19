/*
** my_getnbr.c for libmy in /home/fortev_g/rendu
** 
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
** 
** Started on  Mon Oct 14 13:35:23 2015 Gbariel forteville
** Last update Tue Nov 17 19:13:23 2015 Gabriel Forteville
*/

int	nb_size(char *str, int i)
{
  int	tmp;

  tmp = i;
  while (('0' <= str[tmp]) && (str[tmp] <= '9'))
    tmp++;
  return (tmp - 1);
}

int	count_sign(char *str)
{
  int	sign;
  int	i;

  sign = 0;
  i = 0;
  while (str[i] < '0' || str[i] > '9')
    {
      if (str[i] == '-')
	sign++;
      i++;
    }
  if ((sign % 2) == 0)
    return (1);
  return (0);
}

int	my_get_nbr(char *str)
{
  int	nb;
  int	i;
  int	tmp;
  int	div;

  nb = 0;
  div = 1;
  i = 0;
  while (str[i] < '0' || str[i] > '9')
    i++;
  tmp = nb_size(str, i);
  while (tmp >= i)
    {
      nb = nb + ((str[tmp] - 48) * div);
      div *= 10;
      tmp--;
    }
  if (count_sign(str) == 0)
    nb *= -1;
  return (nb);
}
