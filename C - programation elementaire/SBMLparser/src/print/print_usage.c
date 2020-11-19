/*
** print_usage.c for SBMLparser in /home/fortevg/rendu/SBMLparser
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Mon Jun 13 12:48:55 2016 Gabriel Forteville
** Last update Wed Jun 15 15:30:05 2016 Forteville Gabriel
*/

#include	<stdio.h>
#include	"basic.h"

int		print_usage()
{
  printf("%s", "USAGE\n"
	 "\t./SBMLparser\tSBMLfile [-i ID [-e]] [-json]\n"
	 "DESCRIPTION\n"
	 "\tSBMLfile SBML file\n"
	 "\t-i ID\tid of the compartment, reaction or product to"
	 "be extracted (ignored if uncorrect)\n"
	 "\t-e\tprint the equation if a reaction ID is given as argument"
	 "(ignored otherwise)\n"
	 "\t-json\ttransform the file into a JSON file\n");
    return (84);
}
