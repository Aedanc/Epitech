/*
** get_next_line.c for  in /home/fortevg/rendu/CPE/CPE_2015_getnextline
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan 12 14:41:37 2016 Forteville Gabriel
** Last update Thu Feb 18 12:18:40 2016 Forteville Gabriel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char		*my_strcpy(char *src, int start, int end)
{
  int		i;
  char		*goal;

  i = 0;
  if (end == 0)
    while (src[end] != 0)
      end++;
  goal = malloc((end - start + 1) * sizeof(char));
  while ((start + i) != end)
    {
      goal[i] = src[start + i];
      i++;
    }
  goal[i] = 0;
  return (goal);
}

char		*my_strcat(char *str1, char *str2, int i, int tmp)
{
  char		*str3;

  while (str1[i] != 0)
    i++;
  while (str2[tmp] != 0)
    tmp++;
  if ((str3 = malloc(sizeof(char) * (tmp + i + 1))) == NULL)
    return (NULL);
  i = 0;
  tmp = 0;
  while (str1[i] != 0)
    {
      str3[i] = str1[i];
      i++;
    }
  while (str2[tmp] != 0)
    {
      str3[i] = str2[tmp];
      i++;
      tmp++;
    }
  str3[i] = 0;
  free (str2);
  return (str3);
}

int		copyandsave(char **str, char **save, int i)
{
  free((*save));
  (*save) = my_strcpy((*str), i, 0);
  (*str)[i] = 0;
  while ((*str)[i] != 0)
    {
      (*str)[i] = 0;
      i++;
    }
  return (0);
}

int		tryharder(int fd, char **str, int i, char **save)
{
  char		*tmp;

  if ((tmp = malloc(sizeof(char) * (1000 + 1))) == NULL)
    return (-2);
  if (read(fd, tmp, 1000) == 0)
    {
      free (tmp);
      free ((*save));
      (*save) =  NULL;
      return (-1);
    }
  tmp[1000] = 0;
  i = 0;
  (*str) = my_strcat((*str), tmp, 0, 0);
  while ((*str)[i + 1] != 0)
    if ((*str)[i] == '\n')
      {
	copyandsave(str, save, i + 1);
	return (-1);
      }
    else
     i++;
  return (0);
}

char		*get_next_line(const int fd)
{
  char	 	*str;
  int		i;
  int		tmp;
  static char	*save = NULL;

  if ((str = malloc(((tmp = 1000) + 1) * sizeof(char))) == NULL
      || (i = read(fd, str, 1000)) == -1 || ((i == 0) && save == NULL))
    return (NULL);
  str[i] = 0;
  i = 0;
  str = (save != NULL) ? my_strcat(save, str, 0, 0) : str;
  while (str[i + 1] != 0)
    (str[i] == '\n') ? (tmp = copyandsave(&str, &save, i + 1)) : i++;
  if (tmp != 0)
    while ((i = tryharder(fd, &str, 0, &save)) != -1)
      if (i == -2)
	return (NULL);
  i = 0;
  while (str[i] != 0 && str[i] != '\n')
    i++;
  str[i] = 0;
  if (save != NULL && save[0] == 0)
    return (NULL);
  str[0] = (str[0] == '\n') ? 0 : str[0];
  return (str);
}
