/*
** is_not_in.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Wed Mar 23 18:42:05 2016 Hugo Willaume
** Last update Fri Mar 25 11:05:02 2016 Hugo Willaume
*/

int	is_not_in_i(int *tablo, int nb, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      if (tablo[i] == nb)
	return (1);
      i++;
    }
  return (0);
}
