//
// Input.hpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/includes
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Thu Feb 23 10:32:59 2017 Laurent QUERSIN
// Last update Fri Mar  3 16:42:07 2017 Laurent QUERSIN
//

#ifndef INPUT_HPP_
# define INPUT_HPP_

#include	<map>

#include	"AComponent.hpp"
#include	"PinTypes.hpp"
#include	"Error.hh"

class	Input : public AComponent
{
private:
  PinTypes		_pins[3] = {UNUSED, OUTPUT, INPUT};
  nts::Tristate		_state;
  
public:
  Input(const std::string &);
  ~Input() {}
  nts::Tristate			Compute(size_t pin = 1);
  void				SetLink(size_t, nts::IComponent &, size_t);
  void				Dump() const;
  void				SetState(nts::Tristate);
};

AComponent			*CreateInput(const std::string &);

#endif
