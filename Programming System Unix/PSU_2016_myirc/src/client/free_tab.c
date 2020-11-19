/*
** free_tab.c for PSU_2016_myirc in /home/fortevg/rendu/
**
** Made by Gabriel Forteville
** Login   <Gabriel.Forteville@epitech.eu>
**
** Started on  sam. juin 10 14:24:32 2017 Gabriel Forteville
** Last update sam. juin 10 14:24:32 2017 Gabriel Forteville
*/

#include 	<stdlib.h>

void		free_tab(char **userinput)
{
  int		tab;

  tab = 0;
  if (userinput != NULL)
    {
      while (userinput[tab] != NULL)
	{
	  free(userinput[tab]);
	  tab++;
	}
      free(userinput);
    }
}
