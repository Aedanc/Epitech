/*
** functab.c for PSU_2016_myirc ortevg/rendu/
**
** Made by Gabriel Forteville
** Login   <Gabriel.Forteville@epitech.eu>
**
** Started on  mer. juin 7 16:17:3 2017 Gabriel Forteville
** Last update mer. juin 7 16:17:3 2017 Gabriel Forteville
*/

#include		<string.h>
#include		<stdio.h>
#include		"client/funcTab.h"
#include		"client/structClient.h"

static const fonction	fonc_tab[] = {
	&quit,
	&nick,
	&help,
	&server
};

static const char	*dictionary[4] = {
  "quit",
  "nick",
  "help",
  "server"
};

int			use_command(char **command, t_client *client)
{
  int		i;

  i = 0;
  while (dictionary[i] != NULL && strcmp(dictionary[i], command[0]) != 0)
    i++;
  if (dictionary[i] != NULL)
    return fonc_tab[i](command, client);
  else
    printf("@Console: syntax error, command unknow\r\n");
  return 0;
}
