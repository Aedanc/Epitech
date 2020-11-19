/*
** my_putchar.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM/src/basics
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Mar 22 13:33:49 2016 Hugo Willaume
** Last update Sun Mar 27 05:39:12 2016 Hugo Willaume
*/

#include	<unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
