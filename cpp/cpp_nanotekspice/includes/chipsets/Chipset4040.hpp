//
// Chipset4040.hpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/includes
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Thu Feb 23 11:22:53 2017 Laurent QUERSIN
// Last update Sat Mar  4 00:11:00 2017 Laurent QUERSIN
//

#ifndef CHIPSET4040_HPP_
# define CHIPSET4040_HPP_

#include	"IComponent.hpp"
#include	"Link.hpp"
#include	"Error.hh"
#include	"PinTypes.hpp"

class	Chipset4040 : public AComponent
{
private:
  nts::Tristate _lastState;
  PinTypes _pins[17] =
    {
      UNUSED,
      OUTPUT, OUTPUT, OUTPUT, OUTPUT, OUTPUT, OUTPUT, OUTPUT,
      UNUSED,
      OUTPUT,             
      INPUT, INPUT,
      OUTPUT, OUTPUT, OUTPUT, OUTPUT,                                
      UNUSED

    };
  size_t           _order[17] =
    {
      0, 12, 6, 5, 7, 4, 3, 2, 0, 1, 0, 0, 9, 8, 10, 11, 0
    };
  AComponent *_ordered[13] = {NULL};

public:
  Chipset4040(const std::string &);
  ~Chipset4040();
  nts::Tristate	Compute(size_t pin = 1);
  void		SetLink(size_t, nts::IComponent &, size_t);
  void		Dump() const;
  void		SetState(nts::Tristate);
};

AComponent *Create4040(const std::string &);

#endif
