/*
** nick.c for PSU_2016_myirc in /home/fortevg/rendu/
**
** Made by Gabriel Forteville
** Login   <Gabriel.Forteville@epitech.eu>
**
** Started on  mer. juin 7 20:15:6 2017 Gabriel Forteville
** Last update mer. juin 7 20:15:6 2017 Gabriel Forteville
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"client/structClient.h"

int		nick(char **command, t_client *client)
{
  if (command[1] == NULL)
    printf("@Console: use: /nick $newNickName\n");
  else if (command[2] != NULL)
    printf("@Console: Your login needs to be in one word\n");
  else if (strcmp(command[1], "@Console") == 0)
      printf("No allowed nickname\n");
    else
      {
	free(client->nickname);
	client->nickname = strdup(command[1]);
	printf("Your nickname is now: \"%s\"!\n", client->nickname);
      }
  return (0);
}