/*
** printf.c for my_printf in /home/fortev_g/rendu/PSU_2015_my_printf_bootstrap
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Tue Nov 10 18:30:35 2015 Gabriel Forteville
** Last update Wed Nov 25 01:20:11 2015 Forteville Gabriel
*/
#include <stdarg.h>
#include <stdlib.h>

int		flagschar(char *str, char flag, int compt)
{
  char *tmp;

  tmp = str;
  if (tmp == NULL)
    return (0);
  if (flag == 's')
    {
      my_putstr(str);
      compt =  my_strlen(str);
    }
  else if (flag == 'S')
    compt =  my_putstrflags(str);
  return (compt);
}

int		flagsint(int nbr, char flag, int compt)
{
  if (flag  == 'c')
    my_putchar(nbr);
  else if (flag == 'i' || flag ==  'd')
    my_put_nbr(nbr);
  else if (flag == 'p')
    my_put_pointer_base_long((unsigned long int )nbr, "0123456789abcdef");
  else if (flag == 'o')
    my_put_nbr_base_uns(nbr, "01234567");
  else if (flag == 'u')
    my_put_nbr_base_uns(nbr, "0123456789");
  else if (flag == 'x')
    my_put_nbr_base_uns(nbr, "0123456789abcdef");
  else if (flag == 'X')
    my_put_nbr_base_uns(nbr, "0123456789ABCDEF");
  else if (flag == 'b')
    my_put_nbr_base_uns(nbr, "01");
  else
    my_putchar('%');
  if (flag != 'c')
    while (nbr  > 9)
      {
	nbr = nbr / 10;
	compt++;
      }
  return (++compt);
}

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		i;
  int		compt;

  compt = 0;
  i = -1;
  va_start(ap, format);
  while (i++ < my_strlen(format) - 1)
    {
      if (format[i] != '%')
	{
	  my_putchar(format[i]);
	  compt++;
	}
      else
	{
	  if (format[i + 1] == 's' || format[i + 1] == 'S')
	    compt += flagschar(va_arg(ap, char *), format[i + 1], compt);
	  else
	    compt = flagsint(va_arg(ap, int), format[i + 1], compt);
	  i++;
	}
    }
  va_end(ap);
  return (compt);
}
