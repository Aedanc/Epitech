/*
** my_putchar.c for  in /home/fortevg/rendu/PSU/PSU_2015_my_select
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Dec  8 12:49:44 2015 Forteville Gabriel
** Last update Wed Dec  9 14:34:05 2015 Forteville Gabriel
*/

#include <unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}
