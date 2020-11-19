/*
** my_str_to_word_tab.c in /home/fortevg/rendu/PSU/PSU_2015_minishell1/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan  7 15:39:11 2016 Forteville Gabriel
** Last update Sun May 21 20:51:00 2017 Gabriel Forteville
*/

#include	<unistd.h>
#include	<stdlib.h>

int		checkseparator(char c, char *separator)
{
  int		i;

  i = 0;
  while (separator[i] != 0)
    {
      if (separator[i] == c)
	return 0;
      i++;
    }
  return 1;
}

char		**mallocword(char *str, char **wordtab, char *separator)
{
  int		i;
  int		tmp;
  int		tab;

  tab = 0;
  i = 0;
  while (checkseparator(str[i], separator) == 0)
    i++;
  while (str[i] != 0)
    {
      tmp = i;
      while (checkseparator(str[i], separator) != 0 && str[i] != 0)
	i++;
      if ((wordtab[tab] = malloc(sizeof(char) * (i - tmp + 1))) == NULL)
	return (NULL);
      wordtab[tab][i - tmp] = 0;
      tab++;
      while (checkseparator(str[i], separator) == 0 && str[i] != 0)
	i++;
    }
  return (wordtab);
}

char		**malloctab(char *str, char *separator)
{
  int		i;
  int		space;
  char		**wordtab;

  i = 0;
  while (checkseparator(str[i], separator) == 0)
    i++;
  space = 0;
  while (str[i++] != 0)
    if (checkseparator(str[i], separator) == 0
	&& checkseparator(str[i - 1], separator) != 0 && str[i + 1] != 0)
      space++;
  if ((wordtab = malloc(sizeof(char *) * (space + 2))) == NULL)
    return (NULL);
  wordtab[space] = NULL;
  wordtab[space + 1] = NULL;
  return (wordtab);
}

char		**my_str_to_word_tab(char *str, char *separator)
{
  int		word;
  int		tab;
  int		i;
  char		**wordtab;

  tab = 0;
  i = 0;
  if (str == NULL || (wordtab = malloctab(str, separator)) == NULL ||
      (wordtab = mallocword(str, wordtab, separator)) == NULL)
    return (NULL);
  while (str[i] != 0)
    {
      word = 0;
      while (str[i] != 0 && checkseparator(str[i], separator) == 0)
	i++;
      while (str[i] != 0 && checkseparator(str[i], separator) != 0)
	{
	  wordtab[tab][word] = str[i];
	  i++;
	  word++;
	}
      tab++;
    }
  return (wordtab);
}
