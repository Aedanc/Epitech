/*
** main.c for  in /home/fortevg/test
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan  7 19:12:30 2016 Forteville Gabriel
** Last update Fri Feb 26 21:58:09 2016 Forteville Gabriel
*/

#include <unistd.h>

int	my_show_word_tab(char **str)
{
  int	tab;
  int	word;

  tab = 0;
  while (str[tab] != NULL)
    {
      word = 0;
      while (str[tab][word] != 0)
	{
	  write(1, &str[tab][word], 1);
	  word++;
	}
      tab++;
      write(1, "\n", 1);
    }
  return (0);
}
