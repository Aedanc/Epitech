//
// Picture.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d13
//
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
//
// Started on  Mon Jan 16 09:35:56 2017 Gabriel Forteville
// Last update Mon Jan 16 13:56:46 2017 Gabriel Forteville
//

#include <string>
#include <fstream>
#include "Picture.h"

Picture::Picture():
    _data("")
{}

Picture::Picture(std::string const& file)
{
  std::ifstream afile(file.c_str(), std::ios::in);
  _data = "";
  if(afile.is_open()) {
    std::string buffer;
    while(getline(afile, buffer)) {
      _data += buffer;
      _data += "\n";
    }
    afile.close();
  }
  else {
    _data = "ERROR";
  }
}

Picture::Picture(Picture const& other):
  _data(other._data)
{

}

Picture::~Picture() {}

bool Picture::getPictureFromFile(std::string const& file)
{
  std::ifstream afile(file.c_str(), std::ios::in);
  _data = "";
  if(afile.is_open()) {
    std::string buffer;
    while(getline(afile, buffer)) {
      _data += buffer;
      _data += "\n";
    }
    afile.close();
    return true;
  }
  else {
    _data = "ERROR";
    return false;
  }
}
