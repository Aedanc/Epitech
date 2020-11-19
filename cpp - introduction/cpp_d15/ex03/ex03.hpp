//
// ex03.hpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d15/ex03
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Wed Jan 18 11:47:59 2017 Gabriel Forteville
// Last update Wed Jan 18 12:20:34 2017 Gabriel Forteville
//

#ifndef __EX03_HPP_
# define __EX03_HPP_

#include <iostream>

template <typename T>
void print(T const& a)
{
  std::cout << a << std::endl;
}

template <typename T>
void foreach(T *tab, void (*print)(const T&), int size)
{
  for (int i = 0; i < size; i++)
    {
      print(tab[i]);
    }
};

#endif
