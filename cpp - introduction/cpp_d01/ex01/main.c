/*
** main.c for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d01/ex01
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Jan 04 14:54:02 2017 Forteville Gabriel
** Last update Thu Jan 05 10:16:22 2017 Forteville Gabriel
*/

#include 	<stdlib.h>
#include	<stdio.h>

void		menger(int size, int pa, int po, int end);

int			my_getnbr(char *str);

int				main(int ac, char **av)
{
  int			p;

  if (ac != 3)
    {
      fprintf(stderr, "%s\n", "Error: menger take 2 absolute integer in argument");
      exit(84);
    }
  p = my_getnbr(av[1]) / 3;
  printf("%03d %03d %03d\n", p, p, p);
  menger(p, p, p, my_getnbr(av[2]));
}
