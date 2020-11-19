//
// ex01.hpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d15/ex01
//
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
//
// Started on  Wed Jan 18 10:18:42 2017 Gabriel Forteville
// Last update Wed Jan 18 10:49:30 2017 Gabriel Forteville
//


#ifndef __EX01_HPP_
# define __EX01_HPP_

#include <cstring>

template <typename T>
int compare(T const& a, T const& b)
{
  if (a < b)
    return -1;
  if (a > b)
    return 1;
  return 0;
}

template <>
int compare<const char *>(const char* const& a, const char* const& b)
{
  int i = strcmp(a, b);

  if (i < 0)
    return -1;
  if (i > 0)
    return 1;
  return 0;
}

#endif
