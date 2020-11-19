/*
** basic.c for  in /home/fortevg/rendu/infographie/gfx_scroller/textedéfilant
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sat Mar 19 22:18:24 2016 Forteville Gabriel
** Last update Sun Mar 20 22:06:17 2016 anthony
*/

#include                "scroller.h"

int			nbrinfont(char c)
{
  if (c >= 'a' && c <= 'z')
    return (((int)c - ('a')));
  else if (c >= 'A' && c <= 'Z')
    return (((int)c - ('A')));
  else if (c == ' ')
    return (-2);
  else if (c > '0' && c <= '9')
    return (((int)c - ('0') + 27));
  else if (c == ',')
    return (37);
  else if (c == '.')
    return (38);
  else if (c == ':')
    return (39);
  else if (c == '\'')
    return (40);
  else if (c == '-')
    return (41);
  else if (c == '<')
    return (42);
  else if (c == '>')
    return (43);
  else if (c == '!')
    return (44);
  return (-1);
}
