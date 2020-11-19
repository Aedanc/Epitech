//
// Link.hpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/includes
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Thu Feb 23 10:52:42 2017 Laurent QUERSIN
// Last update Fri Mar  3 21:28:02 2017 Laurent QUERSIN
//

#ifndef LINK_HPP_
# define LINK_HPP_

#include "AComponent.hpp"
#include "PinTypes.hpp"
#include "Error.hh"

class	Link : public AComponent
{
private:
  PinTypes	_pins[3] = {UNUSED, INPUT, OUTPUT};
  nts::Tristate _state;

public:
  Link();
  ~Link();
  nts::Tristate	Compute(size_t pin = 1);
  void		SetLink(size_t, nts::IComponent &, size_t);
  void		Dump() const;
  void		SetState(nts::Tristate);
};

AComponent *CreateLink(const std::string &);

#endif
