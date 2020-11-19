/*
** String.h for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d03/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jan 06 09:29:39 2017 Forteville Gabriel
** Last update Fri Jan 06 09:54:38 2017 Forteville Gabriel
*/

typedef struct String{
  char *str;

  void (*StringInit)(struct String *this, char const *s);
  void (*StringDestroy)(struct String *this);
} String;



void StringInit(struct String *this, char const *s);
void StringDestroy(struct String *this);
