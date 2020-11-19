//
// AObject.cpp for  in /home/hurlu/rendu/cpp_santa/src
// 
// Made by Hugo Willaume
// Login   <willau_h@epitech.net>
// 
// Started on  Sat Jan 14 13:59:48 2017 Hugo Willaume
// Last update Sun Jan 15 00:19:36 2017 Hugo Willaume
//

#include "AObject.hh"

AObject::AObject(std::string _class_name, std::string title) :
  _class(""),
  _title(title)
{
  _class = _class_name;
}

AObject::AObject(AObject const &other) :
  _class(""),
  _title(other._title)
{
  _class = other._class;
}

AObject &AObject::operator=(AObject const &other)
{
  _class = other._class;
  return *this;
}

AObject::~AObject()
{

}

const std::string& AObject::getTitle() const
{
  return _title;
}

const std::string& AObject::getClass() const
{
  return _class;
}
