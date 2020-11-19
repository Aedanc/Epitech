/*
** error.c for projTester in /home/fortevg/rendu/projTester/src/basic
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Jun 22 12:19:42 2016 Forteville Gabriel
** Last update Wed Jun 22 12:25:52 2016 Forteville Gabriel
*/

#include	<stdio.h>
#include	<stdlib.h>

void		error(char *str)
{
  fprintf(stderr, "%s\n", str);
  exit (84);
}
