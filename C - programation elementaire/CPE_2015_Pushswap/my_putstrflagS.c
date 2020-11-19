/*
** my_putstrflagS.c for printf in /home/fortev_g/rendu/PSU_2015_my_printf_bootstrap/lib/my
** 
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
** 
** Started on  Fri Nov 13 15:52:55 2015 Gabriel Forteville
** Last update Sun Nov 15 22:24:43 2015 Gabriel Forteville
*/
int	       my_putstrflagS(char *str)
{
  int	i;
  int	compt;

  compt = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] <= 31 || str[i] >= 127)
	{
	  my_putchar('\\');
	  if (str[i] <= 7)
	    my_putstr("00");
	  else if (str[i] <= 63)
	    my_putchar('0');
	  my_put_nbr_base((int)str[i], "01234567");
	  compt = compt + 4;
	}
      else
	{
	  my_putchar(str[i]);
	  compt = compt + 1;
	}
      i++;
    }
  return (compt);
}
