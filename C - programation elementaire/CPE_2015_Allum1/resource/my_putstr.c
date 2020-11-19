/*
** my_putstr.c for  in /home/fortevg/rendu/PSU/PSU_2015_my_select
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Dec  8 12:41:33 2015 Forteville Gabriel
** Last update Wed Dec  9 14:34:48 2015 Forteville Gabriel
*/

#include <unistd.h>
#include "../my.h"

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
