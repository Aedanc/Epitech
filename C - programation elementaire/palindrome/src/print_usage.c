/*
** print_usage.c for palindrome in /home/fortevg/rendu/palindrome/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jun 16 14:12:45 2016 Forteville Gabriel
** Last update Sat Jun 18 13:38:23 2016 Forteville Gabriel
*/

#include	<stdlib.h>
#include	<stdio.h>

void		print_usage()
{
  fprintf(stderr, "%s\n", "USAGE\n"
	  "\t./palindrome -n number -p palindrome [-b base] [-imin i] "
	  "[-imax i]\n"
	  "\nDESCRIPTION\n"
	  "\t-n nb \t\tinteger to be transformed (≥ 0)\n"
	  "\t-p pal \t\tpalindromic number to be obtained "
	  "(incompatible with the −n option) (≥ 0)\n"
	  "\t\t\tif defined, all fitting values of n will be output\n"
	  "\t-b base \tbase in which the procedure will be executed "
	  "(1 < b ≤ 10) [def: 10]\n"
	  "\t-imin i \tminimum number of iterations, included (≥ 0) [def: 0]\n"
	  "\t-imax i \tmaximum number of iterations, included (≥ 0) [def: 100]\
	  ");
  exit(84);
}
