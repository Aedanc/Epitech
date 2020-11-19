/*
** my_swap.c for my_swap in /home/fortev_g/rendu
** 
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
** 
** Started on  Thu Oct  2 18:34:49 2015 Gabriel Forteville
** Last update Thu Nov  5 09:53:44 2015 Gabriel Forteville
*/
int	my_swap(int *a, int *b)
{
  int	tampon;

  tampon = *a;
  *a = *b;
  *b = tampon;
  return (0);
}
