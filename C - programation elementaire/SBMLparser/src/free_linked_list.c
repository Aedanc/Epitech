/*
** free_linked_list.c for SBMLparser in /home/fortevg/rendu/SBMLparser/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jun 14 21:48:53 2016 Forteville Gabriel
** Last update Tue Jun 14 22:38:53 2016 Forteville Gabriel
*/

#include		<stdlib.h>
#include		"struct.h"
#include		"basic.h"

void			free_linked_list(t_data *info_file)
{
  t_data		*tmp;

  tmp = info_file->next;
  while (tmp != NULL)
    {
      free_tab(info_file->info_line);
      free(info_file);
      info_file = tmp;
      tmp = tmp->next;
    }
  free_tab(info_file->info_line);
  free(info_file);
}
