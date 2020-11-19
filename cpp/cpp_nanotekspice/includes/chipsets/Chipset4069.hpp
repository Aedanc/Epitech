//
// Chipset4069.hpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/includes
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Thu Feb 23 11:22:53 2017 Laurent QUERSIN
// Last update Fri Mar  3 23:41:57 2017 Laurent QUERSIN
//

#ifndef CHIPSET4069_HPP_
# define CHIPSET4069_HPP_

#include	"IComponent.hpp"
#include	"Link.hpp"
#include	"Error.hh"
#include	"PinTypes.hpp"

class	Chipset4069 : public AComponent
{
private:
  PinTypes _pins[15] =
    {
      UNUSED,
      INPUT, OUTPUT,
      INPUT, OUTPUT,
      INPUT, OUTPUT,
      UNUSED,
      OUTPUT, INPUT,
      OUTPUT, INPUT,
      OUTPUT, INPUT,
      UNUSED
    };

public:
  Chipset4069(const std::string &);
  ~Chipset4069();
  nts::Tristate	Compute(size_t pin = 1);
  void		SetLink(size_t, nts::IComponent &, size_t);
  void		Dump() const;
  void		SetState(nts::Tristate);
};

AComponent *Create4069(const std::string &);

#endif
