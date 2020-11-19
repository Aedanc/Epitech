//
// Link.cpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/sources
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Thu Feb 23 10:54:42 2017 Laurent QUERSIN
// Last update Fri Mar  3 21:28:29 2017 Laurent QUERSIN
//

#include "Link.hpp"

Link::Link()
{
  _type = "link";
  _name = "";
  _state = nts::Tristate::UNDEFINED;
  _pinNbr = 1;
  _links.push_back(NULL);
}

Link::~Link()
{
}

nts::Tristate	Link::Compute(size_t pin)
{
  if (pin != 1)
    {
      std::ostringstream        oss;
      oss << "Link on a link: cannot compute pin " << pin;
      throw ComputeError(oss.str());
    }
  return (_state);
}

void		Link::SetLink(size_t from, nts::IComponent &cmp, size_t to)
{
  std::ostringstream    oss;
  oss << "Set Link on a link: pin " << from;

  if (from > 2)
    {
      oss <<  " does not exists.";
      throw LinkError(oss.str());
    }
  if (_pins[from] != INPUT)
    {
      oss << " is not an in pin.";
      throw LinkError(oss.str());
    }
  _links[0] = static_cast<AComponent *>(&cmp);
  cmp.SetLink(to, *this, 0);
}

void		Link::Dump() const
{
  //la focntion qui sert à rien qui est là pour faire beau
  //si quelqu'un voit ça -> http://gifrific.com/you-didnt-see-anything-madagascar/
}

void		Link::SetState(nts::Tristate ns)
{
  _state = ns;
}

AComponent	*CreateLink(const std::string &name)
{
  static_cast<void>(name);
  return (new Link());
}
