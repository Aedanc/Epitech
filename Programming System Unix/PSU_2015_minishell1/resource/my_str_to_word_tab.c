/*
** my_str_to_word_tab.c in /home/fortevg/rendu/PSU/PSU_2015_minishell1/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan  7 15:39:11 2016 Forteville Gabriel
** Last update Mon Jan 25 12:00:35 2016 Forteville Gabriel
*/

#include <unistd.h>
#include <stdlib.h>

char		**mallocword(char *str, char **wordtab, char c)
{
  int		i;
  int		tmp;
  int		tab;

  tab = 0;
  i = 0;
  while (str[i] == c)
    i++;
  while (str[i] != 0)
    {
      tmp = i;
      while (str[i] != c && str[i] != 0)
	i++;
      wordtab[tab] = malloc(sizeof(char) * (i - tmp + 1));
      wordtab[tab][i - tmp] = 0;
      tab++;
      while (str[i] == c && str[i] != 0)
	i++;
    }
  return (wordtab);
}

char		**malloctab(char *str, char c)
{
  int		i;
  int		space;
  char		**wordtab;

  i = 0;
  while (str[i] == c)
    i++;
  space = 0;
  while (str[i++] != 0)
    if (str[i] == c && str[i - 1] != c && str[i + 1] != 0)
      space++;
  wordtab = malloc(sizeof(char *) * (space + 2));
  wordtab[space + 1] = NULL;
  return (wordtab);
}

char		**my_str_to_word_tab(char *str, char c)
{
  int		word;
  int		tab;
  int		i;
  char		**wordtab;

  tab = 0;
  i = 0;
  wordtab = malloctab(str, c);
  wordtab = mallocword(str, wordtab, c);
  while (str[i] != 0)
    {
      word = 0;
      while (str[i] == c && str[i] != 0)
	i++;
      while (str[i] != c && str[i] != 0)
	{
	  wordtab[tab][word] = str[i];
	  i++;
	  word++;
	}
      tab++;
    }
  return (wordtab);
}
