//
// Output.hpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/includes
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Thu Feb 23 10:37:54 2017 Laurent QUERSIN
// Last update Fri Mar  3 16:42:16 2017 Laurent QUERSIN
//

#ifndef OUTPUT_HPP_
# define OUTPUT_HPP_

#include	<map>

#include	"AComponent.hpp"
#include	"PinTypes.hpp"
#include	"Error.hh"

class	Output : public AComponent
{
private:
  PinTypes		_pins[3] = {UNUSED, INPUT, OUTPUT};
  nts::Tristate		_state;

public:
  Output(const std::string &);
  ~Output() {}
  nts::Tristate			Compute(size_t pin = 1);
  void				SetLink(size_t, nts::IComponent &, size_t);
  void				Dump() const;
  void				SetState(nts::Tristate);
};

AComponent		*CreateOutput(const std::string &);

#endif
