/*
** my_strcp.c for  in /home/fortevg/rendu/PSU/PSU_2015_minishell1/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan  7 14:57:50 2016 Forteville Gabriel
** Last update Thu Jan  7 15:17:07 2016 Forteville Gabriel
*/

char	*my_strcpy(char *src, char *goal, int start, int end)
{
  int	i;

  i = 0;
  goal = malloc(sizeof(char) * (end - start + 1));
  while ((start + i) != end)
    {
      goal[i] = src[start + i];
      i++;
    }
  goal[i + 1] = 0;
  return (goal);
}
