/*
** my_putstr.c for lib my in /home/fortev_g/Desktop/libmy
** 
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
** 
** Started on  Thu Nov  5 09:58:14 2015 Gabriel Forteville
** Last update Thu Nov  5 10:08:43 2015 Gabriel Forteville
*/

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
