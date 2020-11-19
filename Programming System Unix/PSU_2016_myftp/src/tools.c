/*
** tools.c for  in /home/fortevg/rendu/PSU/PSU_2016_myftp
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Sat May 13 17:41:59 2017 Gabriel Forteville
** Last update Sun May 21 20:49:36 2017 Gabriel Forteville
*/

#include	<ctype.h>
#include	<unistd.h>
#include	"client.h"
#include	"error.h"
#include	"strtowordtab.h"

int		is_num(char *num)
{
  int		i;

  i = 0;
  while (num[i] != 0)
    {
      if (isdigit(num[i]))
	return -1;
      i++;
    }
  return 0;
}

char		**get_command(struct s_client *client)
{
  char		*tmp;
  size_t	n;
  char		**command;

  tmp = NULL;
  n = 0;
  client->Fp = fdopen(dup(client->fd), "r");
  if (client->Fp == NULL)
    {
      put_error("fdopen");
      return NULL;
    }
  getline(&tmp, &n, client->Fp);
  command = my_str_to_word_tab(tmp, " \r\n");
  if (fclose(client->Fp) != 0)
    {
      put_error("fclose");
      return NULL;
    }
  return command;
}
