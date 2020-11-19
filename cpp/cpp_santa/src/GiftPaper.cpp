//
// GiftPaper.cpp for  in /home/hurlu/rendu/cpp_santa
// 
// Made by Hugo Willaume
// Login   <willau_h@epitech.net>
// 
// Started on  Sat Jan 14 14:21:53 2017 Hugo Willaume
// Last update Sun Jan 15 09:21:02 2017 Hugo Willaume
//

#include "GiftPaper.hh"

GiftPaper::GiftPaper() : AWrap("giftPaper", "Gift paper")
{
}

GiftPaper::GiftPaper(GiftPaper const &other) : AWrap(other._class,
						     other._title)
{
}

GiftPaper & GiftPaper::operator=(GiftPaper const &other)
{
  _class = other._class;
  _gift = other._gift;
  _empty = other._empty;
  _title = other._title;
  return *this;
}

GiftPaper::~GiftPaper()
{
}

void GiftPaper::wrapMeThat(IObject* &obj)
{
  if (!IsEmpty())
    return ;
  std::swap(obj, _gift);
  _empty = false;
  std::cout << "tuuuut tuuut tuut" << std::endl;
}


IObject *GiftPaper::clone() const
{
  return new GiftPaper();
}
