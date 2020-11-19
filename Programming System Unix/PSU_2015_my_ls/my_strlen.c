/*
** my_strlen.c for my_strlen in /home/fortev_g/rendu/
** 
** Made by Gabriel Forteville
** Login   <willau_h@epitech.net>
** 
** Started on  Thu Oct  1 14:38:25 2015 Gabriel Forteville
** Last update Thu Nov  5 09:51:55 2015 Gabriel Forteville
*/

int	my_strlen(char *str)
{
  int	i;

  i = 1;
  while (str[i] != '\0')
    i++;
  return (i);
}
