//
// Input.cpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/sources
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Thu Feb 23 10:34:24 2017 Laurent QUERSIN
// Last update Fri Mar  3 16:41:05 2017 Laurent QUERSIN
//

#include "Input.hpp"

Input::Input(const std::string &name)
{
  _type = "input";
  _name = name;
  _state = nts::Tristate::UNDEFINED;
  _pinNbr = 1;
  _links.push_back(NULL);
}

nts::Tristate	Input::Compute(size_t pin)
{
  if (pin != 1)
    {
      std::ostringstream        oss;
      oss << "Input " << _name <<": cannot compute pin " << pin;
      throw ComputeError(oss.str());
    }
  return (_state);
}

void		Input::SetLink(size_t from, nts::IComponent &cmp, size_t to)
{
  std::ostringstream    oss;
  oss << "Set Link on " << _name <<": pin " << from;

  if (from > 2)
    {
      oss <<  " does not exists.";
      throw LinkError(oss.str());
    }
  if (_pins[from] != OUTPUT)
    {
      oss << " is not an out pin.";
      throw LinkError(oss.str());
    }
  _links[0] = static_cast<AComponent *>(&cmp);
  cmp.SetLink(to, *this, 0);  
}

void		Input::Dump() const
{
  if (_state == nts::Tristate::TRUE)
    std::cout << "TRUE" << std::endl;
  else if (_state == nts::Tristate::FALSE)
    std::cout << "FALSE" << std::endl;
  else
    std::cout << "UNDEFINED" << std::endl;
}

void		Input::SetState(nts::Tristate ns)
{
  _state = ns;
  if (_links[0] != NULL && _links[0]->getType() == "output")
    {
      _links[0]->SetState(ns);
    }
}

AComponent	*CreateInput(const std::string &name)
{
  return (new Input(name));
}
