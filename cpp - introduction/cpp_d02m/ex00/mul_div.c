/*
** mul_div.c for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d02m/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 05 11:28:15 2017 Forteville Gabriel
** Last update Thu Jan 05 11:37:33 2017 Forteville Gabriel
*/

void		add_mul_4param(int first, int second , int *add, int *mul)
{
  *add = first + second;
  *mul = first * second;
}

void		add_mul_2param(int *first, int *second)
{
  int		plop = *first;
  int		plop2 = *second;

  *first = plop + plop2;
  *second = plop * plop2;
}
