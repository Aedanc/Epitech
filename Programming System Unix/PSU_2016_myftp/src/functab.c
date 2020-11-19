/*
** functab.c for  in /home/fortevg/rendu/PSU/PSU_2016_myftp
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Sat May 20 22:18:09 2017 Gabriel Forteville
** Last update Sun May 21 19:59:14 2017 Gabriel Forteville
*/

#include		<unistd.h>
#include		<string.h>
#include		"functab.h"

static const fonction	fonc_tab[] = {
  &pwd,
  &cwd,
  &cdup,
  &help,
  &noop,
  &dele
};

static const char	*dictionary[6] = {
  "PWD",
  "CWD",
  "CDUP",
  "HELP",
  "NOOP",
  "DELE"
};

int			exec_command(char **command, struct s_client *client)
{
  int		i;

  i = 0;
  while (dictionary[i] != NULL && strcmp(dictionary[i], command[0]) != 0)
    i++;
  if (dictionary[i] != NULL)
    return fonc_tab[i](command, client);
  else
    write(client->fd, "500 syntax error, command unknow\r\n", 34);
  return 0;
}
