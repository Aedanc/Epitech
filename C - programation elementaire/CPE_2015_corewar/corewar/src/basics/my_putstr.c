/*
** my_putstr.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM/src/basics
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Mar 22 13:34:55 2016 Hugo Willaume
** Last update Sun Mar 27 05:40:08 2016 Hugo Willaume
*/

#include	<unistd.h>
#include	"basics.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
