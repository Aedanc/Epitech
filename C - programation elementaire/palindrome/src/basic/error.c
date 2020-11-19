/*
** error.c for palindrome in /home/fortevg/rendu/palindrome/src/basic
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jun 16 14:09:13 2016 Forteville Gabriel
** Last update Sat Jun 18 12:56:48 2016 Forteville Gabriel
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"struct.h"

void		error(char *error, t_data *opt)
{
  free(opt->nbr);
  free(opt->pal);
  free(opt->nbr_save);
  fprintf(stderr, "%s\n", error);
  exit (84);
}
