/*
** my_putchar.c for  in /home/fortevg/rendu/PSU/PSU_2015_minitalk/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Feb  3 14:11:57 2016 Forteville Gabriel
** Last update Wed Feb  3 14:15:30 2016 Forteville Gabriel
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
