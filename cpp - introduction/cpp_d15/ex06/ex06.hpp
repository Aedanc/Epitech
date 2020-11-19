//
// ex06.hpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d15/ex06
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Wed Jan 18 18:48:50 2017 Gabriel Forteville
// Last update Thu Jan 19 09:34:11 2017 Gabriel Forteville
//

#ifndef __EX06_HPP_
# define __EX06_HPP_

#include <iostream>
#include <string>
#include <sstream>

template <typename T>
  std::string printVar(T const& a) {
  std::stringstream result;
  (void)a;
  result << "[???]";
  return result.str();
}

template<>
  std::string printVar(int const& a) {
  std::stringstream result;

  result << "[int:" << a << "]";
  return result.str();
  }

template<>
  std::string printVar(float const&  a) {
  std::stringstream result;

  result << "[float:" << a << "f]";
  return result.str();
  }

template<>
std::string printVar(std::string const& a) {
  std::stringstream result;

  result << "[string:\"" << a << "\"]";
  return result.str();
  }

template <typename T, typename U = T>
class Tuple
{
public:
  T a;
  U b;

  std::string toString() const {
    std::stringstream name;
    name << "[TUPLE " <<  printVar<T>(a) << " " << printVar<U>(b) << "]";
    return name.str();
  }
};
#endif
