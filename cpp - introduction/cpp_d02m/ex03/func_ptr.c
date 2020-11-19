/*
** func_ptr.c for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d02m/ex03
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 05 14:01:51 2017 Forteville Gabriel
** Last update Thu Jan 05 20:25:12 2017 Forteville Gabriel
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func_ptr.h"

void 	print_normal(char *str)
{
  printf("%s\n", str);
}

void print_reverse(char *str)
{
  for (unsigned int i = strlen(str); i >= 0; i--) {
      printf("%c", str[i]);
    }
  printf("\n");
}
void print_upper(char *str)
{
    for (unsigned int i = 0; i < strlen(str); i++) {

      if (str[i] >= 97 && str[i] <= 122)
	printf("%c", str[i] - 32);
      else
	printf("%c", str[i]);
    }
  printf("\n");
}

void print_42(char *str)
{
  (void)str;
  printf("%s\n", "42");
}


void do_action(t_action action, char *str)
{
  void (*function[4])(char *str) = {print_normal, print_reverse, print_upper, print_42};
  function[action](str);
}
