/*
** func_ptr.h for piscine_cpp in /home/fortevg/rendu/piscine_cpp/cpp_d02m/ex03
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan 05 14:41:24 2017 Forteville Gabriel
** Last update Thu Jan 05 14:54:43 2017 Forteville Gabriel
*/

#ifndef FUNC_PTR_H_
# define FUNC_PTR_H_

#include "func_ptr_enum.h"

typedef struct s_func
{
  void (*function[4])(char *str);
}			t_func;

#endif
