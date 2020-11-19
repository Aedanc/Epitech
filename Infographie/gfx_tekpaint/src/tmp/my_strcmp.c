/*
** my_strcmp.c for  in /home/hurlu/rendu/gfx_tekpaint/src/tmp
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Jan 26 22:04:01 2016 Hugo Willaume
** Last update Tue Jan 26 23:03:10 2016 Hugo Willaume
*/

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] == str2[i] && str1[i] != 0 && str2[i] != 0)
    i++;
  if (str1[i] == 0 && str2[i] == 0)
    return (0);
  return (-1);
}
