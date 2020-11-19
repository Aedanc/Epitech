/*
** Picture.h for  in /home/fortevg/rendu/piscine_cpp/cpp_d13
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Mon Jan 16 09:24:41 2017 Gabriel Forteville
** Last update Mon Jan 16 12:06:37 2017 Gabriel Forteville
*/

#ifndef __PICTURE_H_
#define __PICTURE_H_

#include <string.h>

class Picture
{

 public:
  Picture();
  Picture(std::string const& file);
  Picture(Picture const& other);
  ~Picture();

  std::string _data;

  bool getPictureFromFile(const std::string& file);
};

#endif
