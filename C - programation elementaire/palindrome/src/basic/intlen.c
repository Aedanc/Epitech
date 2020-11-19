/*
** intlen.c for palindrome in /home/fortevg/rendu/palindrome/src/basic
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jun 17 10:37:00 2016 Forteville Gabriel
** Last update Fri Jun 17 17:30:22 2016 Forteville Gabriel
*/

int			intlen(int nbr)
{
  int			result;

  result = 0;
  while (nbr != 0)
    {
      result++;
      nbr /= 10;
    }
  return (result);
}
