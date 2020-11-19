//
// AComponent.cpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/sources
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Thu Feb 23 13:40:12 2017 Laurent QUERSIN
// Last update Fri Mar  3 19:43:44 2017 Laurent QUERSIN
//

#include "AComponent.hpp"

AComponent::AComponent()
{
  depth = 0;
  lastVisitedBy = "";
  _name = "";
  _type = "";
  _pinNbr = 0;
}

std::string	AComponent::getName() const
{
  return (_name);
}

std::string	AComponent::getType() const
{
  return (_type);
}

size_t		AComponent::getPinNbr() const
{
  return (_pinNbr);
}

AComponent	*AComponent::getLinkedCmp(size_t pin) const
{
  if (pin >= _pinNbr)
    return (NULL);
  return (_links[pin]);
}
