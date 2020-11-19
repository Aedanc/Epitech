/*
** power_of_two.c for power_of_two in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Mar 24 22:16:39 2016 Hugo Baldassin
** Last update Thu Mar 24 23:02:57 2016 Hugo Baldassin
*/

long		power_of_two(int n)
{
  long		nb;

  nb = 1;
  n *= 8;
  while (n > 1)
    {
      nb *= 2;
      n--;
    }
  return (nb);
}
