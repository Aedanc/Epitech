/*
** my_strlen.c for  in /home/fortevg/rendu/PSU/PSU_2015_my_select
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Dec  8 12:43:16 2015 Forteville Gabriel
** Last update Tue Dec  8 12:49:20 2015 Forteville Gabriel
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}
