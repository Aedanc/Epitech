/*
** error.c for calendar in /home/fortevg/rendu/calendar/src/basic
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jul 01 14:53:45 2016 Forteville Gabriel
** Last update Fri Jul 01 14:56:15 2016 Forteville Gabriel
*/

#include	<stdio.h>
#include	<stdlib.h>

void		error(char *error)
{
  fprintf(stderr, "%s\n", error);
  exit(84);
}
