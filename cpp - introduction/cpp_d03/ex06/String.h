/*
** String.h for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d03/ex00
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jan 06 09:29:39 2017 Forteville Gabriel
** Last update Fri Jan 06 11:21:44 2017 Forteville Gabriel
*/

#ifndef String_H_
# define String_H_

#include <stdlib.h>

typedef struct String {
  char *str;

  void (*StringDestroy)(struct String *this);

  void (*assign_s)(struct String *this, struct String const *str);
  void (*assign_c)(struct String* this, char const *s);

  void (*append_s)(struct String *this, struct String const *ap);
  void (*append_c)(struct String *this, char const *aps);

  char (*at)(struct String *this, size_t pos);

  void (*clear)(struct String *this);

  int (*size)(struct String *this);

  int (*compare_s)(struct String *this, const struct String *str);
  int (*compare_c)(struct String *this, char const *str);

} String;



void StringInit(struct String *this, char const *s);
void StringDestroy(struct String *this);

#endif
