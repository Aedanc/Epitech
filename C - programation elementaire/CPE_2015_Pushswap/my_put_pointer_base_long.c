/*
** my_put_pointer.c for my_printf in /home/fortev_g/rendu/PSU_2015_my_printf_bootstrap
** 
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
** 
** Started on  Thu Nov 12 15:20:04 2015 Gabriel Forteville
** Last update Sun Nov 22 19:33:46 2015 Gabriel Forteville
*/
int		nbr(unsigned long int p, char *base)
{
  unsigned long int tamp;

  if (p < my_strlen(base) && p >= 0 || p > -my_strlen(base) && p <= 0)
    {
      if (p < 0)
	{
	  my_putchar('-');
	  my_putchar(base[p * -1]);
	}
      else
	my_putchar(base[p]);
      return (0);
    }
  tamp = p;
  p = p / my_strlen(base);
  nbr(p, base);
  p = tamp % my_strlen(base);
  if (p < 0)
    my_putchar(base[p * (-1)]);
  else
    my_putchar(base[p]);
}
int		my_put_pointer_base_long(unsigned long int p, char *base)
{
  my_putstr("0x");
  nbr(p, base);
}
