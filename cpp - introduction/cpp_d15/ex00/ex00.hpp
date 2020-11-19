//
// ex00.hpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d15/ex00
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Wed Jan 18 09:56:22 2017 Gabriel Forteville
// Last update Wed Jan 18 10:15:11 2017 Gabriel Forteville
//

#ifndef __EX_00_HPP_
# define __EX_00_HPP_

template <typename T>
void swap(T &a, T &b)
{
  T c = a;

  a = b;
  b = c;
}

template <typename T>
T min(T a, T b)
{
  if (a < b)
    return a;
  return b;
}

template <typename T>
T max(T a, T b)
{
  if (a > b)
    return a;
  return b;
}

template <typename T>
T add(T a, T b)
{
  return a + b;
}

#endif
