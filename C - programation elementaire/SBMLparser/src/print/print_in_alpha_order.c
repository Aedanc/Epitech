/*
** print_in_alpha_order.c for SBMLparser in /home/fortevg/rendu/SBMLparser/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jun 14 16:02:24 2016 Forteville Gabriel
** Last update Wed Jun 15 12:46:31 2016 Forteville Gabriel
*/

#define		_BSD_SOURCE
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	"struct.h"

static void		print_atribute(char **info_line,
				       int index,
				       int cpt,
				       char *comp)
{
  int		print;

  print = 0;
  while (info_line[index + 1] != NULL)
    {
      cpt = 0;
      if (info_line[index][0] == '\'' || info_line[index][0] == '\"')
	print = 1;
      if (print == 0 && strncasecmp(comp, info_line[index],
				    sizeof(char) * 2) == 0)
	printf("----->%s\n", info_line[index]);
      if (print == 1)
	{
	  while (info_line[index][cpt] != 0)
	    cpt++;
	  if (info_line[index][cpt - 1] == '\'' ||
	      info_line[index][cpt - 1] == '\"')
	    print = 0;
	}
      index++;
    }
}

static char		*print_tag(char **info_line)
{
  static char		*str_print = NULL;
  char			*comp;

  comp = strdup("aa");
  if ((str_print == NULL || strcmp(info_line[0], str_print) != 0)
      && info_line[2] != NULL && strcmp(info_line[0], "xml") != 0)
    {
      printf("%s\n", info_line[0]);
      if (str_print != NULL)
	free(str_print);
      str_print = strdup(info_line[0]);
      while (strcmp(comp, "zz") != 0)
	{
	  print_atribute(info_line, 1, 0, comp);
	  comp[1]++;
	  if (comp[1] == 'z' + 1 && comp[0] != 'z' + 1)
	    comp[0]++;
	  if (comp[1] == 'z' + 1 && comp[0] != 'z' + 1)
	    comp[1] = 'a';
	}
    }
  free(comp);
  return (str_print);
}

void		print_in_alpha_order(t_data *info_file)
{
  char		*comp;
  t_data	*tmp;
  char		*for_free;

  for_free = NULL;
  comp = strdup("aa");
  while (strcmp(comp, "zz") != 0)
    {
      tmp = info_file;
      while (tmp != NULL)
	{
	  if (strncasecmp(tmp->info_line[0], comp,
			  (sizeof(char) * 2)) == 0)
	    for_free = print_tag(tmp->info_line);
	  tmp = tmp->next;
	}
      comp[1]++;
      if (comp[1] == 'z' + 1 && comp[0] != 'z' + 1)
	comp[0]++;
      if (comp[1] == 'z' + 1 && comp[0] != 'z' + 1)
	comp[1] = 'a';
    }
  free(for_free);
  free(comp);
}
