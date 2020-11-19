//
// Output.cpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/sources
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Thu Feb 23 10:47:55 2017 Laurent QUERSIN
// Last update Fri Mar  3 22:00:26 2017 Laurent QUERSIN
//

#include "Output.hpp"

Output::Output(const std::string &name)
{
  _type = "output";
  _name = name;
  _state = nts::Tristate::UNDEFINED;
  _links.push_back(NULL);
}

nts::Tristate	Output::Compute(size_t pin)
{
  if (pin != 1)
    {
      std::ostringstream        oss;
      oss << "Output " << _name <<": cannot compute pin " << pin;
      throw ComputeError(oss.str());
    }
  return (_state);
}

void		Output::SetLink(size_t from, nts::IComponent &cmp, size_t to)
{  
  std::ostringstream    oss;
  oss << "Set Link on " << _name <<": pin " << from;

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
  _links[0] = static_cast<AComponent*>(&cmp);
  if (to != 0)
    cmp.SetLink(to, *this, 0);
}

void		Output::Dump() const
{
  if (_state == nts::Tristate::TRUE)
    std::cout << "TRUE" << std::endl;
  else if (_state == nts::Tristate::FALSE)
    std::cout << "FALSE" << std::endl;
  else
    std::cout << "UNDEFINED" << std::endl;
}

void		Output::SetState(nts::Tristate ns)
{
  _state = ns;
}

AComponent	*CreateOutput(const std::string &name)
{
  return (new Output(name));
}
