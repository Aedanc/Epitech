/*
** cdup.c for  in /home/fortevg/rendu/PSU/PSU_2016_myftp
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Sun May 21 18:59:58 2017 Gabriel Forteville
** Last update Sun May 21 20:53:39 2017 Gabriel Forteville
*/

#include	"client.h"

int		cwd(char **, struct s_client *);

int		cdup(char **command, struct s_client *client)
{
  static char		*move[2] = {"plop", ".."};

  (void)command;
  cwd(move, client);
  return 0;
}
