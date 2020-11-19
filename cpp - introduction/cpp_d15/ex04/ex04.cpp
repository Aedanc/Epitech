//
// ex04.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d15/ex04
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Wed Jan 18 13:42:11 2017 Gabriel Forteville
// Last update Wed Jan 18 15:08:48 2017 Gabriel Forteville
//

#include <string>
#include "ex04.hpp"

template <typename T>
bool equal(T const& a, T const& b)
{
  return (a == b);
}

template <typename T>
bool  Tester<T>::equal(T const& a, T const& b)
{
  return (a == b);
}


template bool equal<int>(int const& a, int const& b);

template bool equal<float>(float const& a, float const& b);

template bool equal<double>(double const& a, double const& b);

template bool equal<std::string>(std::string const& a, std::string const& b);


template bool Tester<int>::equal(int const& a, int const& b);

template bool Tester<float>::equal(float const& a, float const& b);

template bool Tester<double>::equal(double const& a, double const& b);

template bool Tester<std::string>::equal(std::string const& a, std::string const& b);


