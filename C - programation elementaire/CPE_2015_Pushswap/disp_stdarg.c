/*
** disp_stdarg.c for bootstrap printf in /home/fortev_g/Desktop/libmy
** 
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
** 
** Started on  Thu Nov  5 12:00:46 2015 Gabriel Forteville
** Last update Wed Nov 11 14:26:00 2015 Gabriel Forteville
*/
#include <stdarg.h>

int	disp_stdarg(char *s, ...)
{
  va_list	ap;
  int		compteur;
  int		i;

  i = 0;
  compteur = -1;
  va_start(ap, s);
  while (compteur++ != my_strlen(s))
    {
      if (s[i] = 'c')
	my_putchar(va_arg(ap, int));
      else if (s[i] = 's')
	my_putstr(va_arg(ap, char *));
      else if (s[i] = 'i')
	my_putnbr(va_arg(ap, int));
    }
  return (0);
}
