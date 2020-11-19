//
// find.hpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d17/ex00
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Fri Jan 20 10:37:56 2017 Gabriel Forteville
// Last update Fri Jan 20 11:30:26 2017 Gabriel Forteville
//

#ifndef _FIND_HPP_
# define _FIND_HPP_

# include <algorithm>

template <typename T>
typename T::iterator do_find(T & contaigner, int search)
{
  return (std::find(contaigner.begin(), contaigner.end(), search));
}

#endif
