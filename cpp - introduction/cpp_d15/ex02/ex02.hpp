//
// ex02.hpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d15/ex00
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Wed Jan 18 09:56:22 2017 Gabriel Forteville
// Last update Wed Jan 18 11:39:47 2017 Gabriel Forteville
//

#ifndef __EX02_HPP_
# define __EX02_HPP_

#include <iostream>

template <typename T>
T min(T const& a, T const&  b)
{
  std::cout << "template min" << std::endl;
  if (a < b)
    return a;
  return b;
}

int min(int a, int b)
{
  std::cout << "non-template min" << std::endl;
  if (a < b)
    return a;
  return b;
}

template <typename T>
T templateMin(T* a, int size)
{
  T result = a[0];
  for (int i = 1; i < size; i++)
    {
      result = min<T>(result, a[i]);
    }
  return result;
}

int nonTemplateMin(int *a, int size)
{
  int result = a[0];

  for (int i = 1; i < size; i++)
    {
      result = min(result, a[i]);
    }
  return result;
}

#endif
