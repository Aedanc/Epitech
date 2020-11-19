/*
** execCommand.c for PSU_2016_myIRC in /home/fortevg/rendu/
**
** Made by Gabriel Forteville
** Login   <Gabriel.Forteville@epitech.eu>
**
** Started on  mer. juin 7 15:18:5 2017 Gabriel Forteville
** Last update mer. juin 7 15:18:5 2017 Gabriel Forteville
*/

#include <stdio.h>
#include "client/useCommand.h"
#include "client/strtowordtab.h"
#include "client/structClient.h"

void		execCommand(t_client *client, char *line, ssize_t lenLine)
{
  char		**command;

  line[lenLine] = 0;
  command = my_str_to_word_tab(line, " /\r\n\t");
  use_command(command, client);
  free_tab(command);
}