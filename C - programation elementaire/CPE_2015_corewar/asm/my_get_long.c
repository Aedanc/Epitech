/*
** my_get_long.c for my_get_long in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Mar 24 23:07:04 2016 Hugo Baldassin
** Last update Thu Mar 24 23:37:52 2016 Hugo Baldassin
*/

long		my_get_long(char *str)
{
  long		nb;
  int		i;

  i = (str[0] == '-') ? 1 : 0;
  nb = 0;
  while (str[i] != '\0')
    {
      nb *= 10;
      nb += str[i] - 48;
      i++;
    }
  if (str[0] == '-')
    return (-nb);
  return (nb);
}
