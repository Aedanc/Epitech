/*
** print_species.c for SBMLparser in /home/fortevg/rendu/SBMLparser/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Jun 15 11:32:33 2016 Forteville Gabriel
** Last update Wed Jun 15 15:41:30 2016 Forteville Gabriel
*/

#include	<string.h>
#include	<stdio.h>
#include	"struct.h"

static void		check_for_print(char **info_line, int index)
{
  int		check;
  int		tmp;

  check = 0;
  while (info_line[index] != NULL && check == 0)
    {
      tmp = -1;
      while (info_line[index][++tmp] != 0)
	{
	  if (info_line[index][tmp] != '\'')
	    printf("%c", info_line[index][tmp]);
	}
      if (info_line[index][tmp - 1] == '\'')
	check = 1;
      if (check != 1)
	printf(" ");
      index++;
    }
}

static void		print_name(char **info_line)
{
  int		index;

  index = 0;
  while (info_line[index] != NULL && strcmp(info_line[index], "name") != 0)
    index++;
  if (info_line[index] == NULL)
    return ;
  index++;
  printf("----->");
  check_for_print(info_line, index);
  printf("\n");
}

void		 print_species(t_data *info_file)
{
  t_data	*tmp;

  tmp = info_file;
  printf("List of species\n");
  while (tmp != NULL)
    {
      if (strcmp(tmp->info_line[0], "species") == 0)
	print_name(tmp->info_line);
      tmp = tmp->next;
    }
}
