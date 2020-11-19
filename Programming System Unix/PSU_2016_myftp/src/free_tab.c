/*
** free_tab.c for  in /home/fortevg/rendu/PSU/PSU_2016_myftp
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Sun May 21 20:50:21 2017 Gabriel Forteville
** Last update Sun May 21 20:50:38 2017 Gabriel Forteville
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
