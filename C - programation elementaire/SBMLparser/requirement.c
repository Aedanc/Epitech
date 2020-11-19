/*
** requirement.c for  in /home/fortevg/rendu/SBMLparser
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Mon Jun 13 9:10:03 2016 Gabriel Forteville
** Last update Wed Jun 15 12:57:32 2016 Forteville Gabriel
*/

#include <unistd.h>
#include <stdlib.h>

static int		is_alphanum(char c)
{
  if ((c >= 'a' && c <= 'z') ||
      (c >= '0' && c <= '9') ||
      (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}

static char		**mallocword(char *str, char **wordtab)
{
  int		index;
  int		tmp;
  int		tab;

  tab = 0;
  index = 0;
  while (is_alphanum(str[index]) == 0)
    index++;
  while (str[index] != 0)
    {
      tmp = index;
      while (is_alphanum(str[index]) != 0 && str[index] != 0)
	index++;
      if ((wordtab[tab] = malloc(sizeof(char) * (index - tmp + 1))) == NULL)
	return (NULL);
      wordtab[tab][index - tmp] = 0;
      tab++;
      while (is_alphanum(str[index]) == 0 && str[index] != 0)
	index++;
    }
  return (wordtab);
}

static char		**malloctab(char *str)
{
  int		index;
  int		separator;
  char		**wordtab;

  index = 0;
  while (is_alphanum(str[index]) == 0)
    index++;
  separator = 0;
  while (str[index++] != 0)
    {
      if ((is_alphanum(str[index]) == 0 &&
	   is_alphanum(str[index - 1]) != 0 && str[index + 1]) != 0)
	separator++;
    }
  if ((wordtab = malloc(sizeof(char *) * (separator + 2))) == NULL)
    return (NULL);
  wordtab[separator] = NULL;
  wordtab[separator + 1] = NULL;
  return (wordtab);
}

char		**my_strtowordtab_synthesis(char *str)
{
  int		word;
  int		tab;
  int		index;
  char		**wordtab;

  tab = 0;
  index = 0;
  if (str == NULL || (wordtab = malloctab(str)) == NULL ||
      (wordtab = mallocword(str, wordtab)) == NULL)
    return (NULL);
  while (str[index] != 0)
    {
      word = 0;
      while (is_alphanum(str[index]) == 0 && str[index] != 0)
	index++;
      while (is_alphanum(str[index]) != 0 && str[index] != 0)
	{
	  wordtab[tab][word] = str[index];
	  index++;
	  word++;
	}
      tab++;
    }
  return (wordtab);
}
