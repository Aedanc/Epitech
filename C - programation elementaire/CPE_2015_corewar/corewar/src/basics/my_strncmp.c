/*
** my_strncmp.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM/src/basics
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Mar 22 16:54:41 2016 Hugo Willaume
** Last update Sun Mar 27 05:41:42 2016 Hugo Willaume
*/

int	my_strncmp(char *str1, char *str2, int max)
{
  int	i;

  i = 0;
  while (str1[i] != 0 && str2[i] != 0 && i < max)
    {
      if (str1[i] != str2[i])
	return (-1);
      i++;
    }
  if (str1[i] != str2[i] && i != max)
    return (-1);
  return (0);
}
