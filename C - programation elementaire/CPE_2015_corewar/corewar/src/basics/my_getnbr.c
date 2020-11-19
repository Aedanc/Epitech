/*
** my_getnbr.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM/src/basics
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Mar 22 13:42:08 2016 Hugo Willaume
** Last update Wed Mar 23 13:47:19 2016 Hugo Willaume
*/

int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	sign;

  nb = 0;
  i = -1;
  sign = 1;
  while (str[++i] != 0 && str[i] == '-')
    if (str[i] == '-')
      sign *= -1;
  if (str[i] < '0' || str[i] > '9')
    return (-9320);
  while (str[i] != 0)
    {
      if (str[i] < '0' || str[i] > '9')
	return (-9320);
      nb *= 10;
      nb += str[i] - '0';
      i++;
    }
  nb *= sign;
  return (nb);
}
