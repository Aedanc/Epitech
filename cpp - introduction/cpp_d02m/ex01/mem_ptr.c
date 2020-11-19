/*
** mem_ptr.c for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d02m/ex01
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 05 11:41:12 2017 Forteville Gabriel
** Last update Thu Jan 05 12:13:49 2017 Forteville Gabriel
*/

#include <stdlib.h>
#include <string.h>
#include "mem_ptr.h"

void add_str(char *str1, char *str2, char **res)
{
  int len1  = strlen(str1) + strlen(str2) + 1;
  if ((*res = malloc(len1)) == NULL)
    return ;
  strcpy(*res, str1);
  strcat(*res, str2);
}

void add_str_struct(t_str_op *str_op)
{
  int len1 = sizeof(char) * (strlen(str_op->str1) + strlen(str_op->str2) + 1);
  if ((str_op->res = malloc(len1)) == NULL)
    return ;
  strcpy(str_op->res, str_op->str1);
  strcat(str_op->res, str_op->str2);
}
