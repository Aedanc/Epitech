/*
** my_strcmp.c for SBLMparser in /home/fortevg/rendu/SBMLparser/src/basic
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Jun 13 13:15:29 2016 Forteville Gabriel
** Last update Wed Jun 15 13:20:41 2016 Forteville Gabriel
*/

#include		<unistd.h>

int			my_strncmp(const char *s1, const char *s2,
				   int start, int end)
{
  int			is_equal;
  int			index;

  index = 0;
  is_equal = 1;
  if (s1 == NULL || s2 == NULL || start < 0)
    return (-2);
  while (s1[start] != 0 && s2[index] != 0 && index != end)
    {
      if (s2[index] != s1[start])
	is_equal = 0;
      start++;
      index++;
    }
  if (s1[start] == s2[index] && is_equal == 1)
    return (0);
  if (s1[start] == 0 && s2[index] != 0)
    return (-1);
  return (1);
}
