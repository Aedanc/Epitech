/*
** help.c for PSU_2016_myirc in /home/fortevg/rendu/
**
** Made by Gabriel Forteville
** Login   <Gabriel.Forteville@epitech.eu>
**
** Started on  mer. juin 7 20:40:3 2017 Gabriel Forteville
** Last update mer. juin 7 20:40:3 2017 Gabriel Forteville
*/

#include	<stdio.h>
#include	"client/structClient.h"

int		help(char **command, t_client *client)
{
  (void)command;
  (void)client;
  printf("@Console:\n");
  printf("help:\n/quit:\n\tuse: /quit\n\texit a server, if no connected ");
  printf("to a server leave the client\n/nick:\n\tuse: /nick $newNickNa");
  printf("me\n\tchange the actual nickname by $newNickName\n/help\n\tuse: /");
  printf("help \n\tDisplay this help\n");
  return (0);
}