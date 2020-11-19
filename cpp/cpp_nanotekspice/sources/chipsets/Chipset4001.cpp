//
// Chipset4001.cpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/sources
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Thu Feb 23 11:29:31 2017 Laurent QUERSIN
// Last update Sat Mar  4 00:45:18 2017 Laurent QUERSIN
//

#include "Chipset4001.hpp"

Chipset4001::Chipset4001(const std::string &name)
{
  _type = "4001";
  _name = name;
  _pinNbr = 15;
  for (size_t i = 0; i < _pinNbr; ++i)
      _links.push_back(NULL);
}

Chipset4001::~Chipset4001()
{
}

nts::Tristate	Chipset4001::Compute(size_t pin)
{
  nts::Tristate i1;
  nts::Tristate i2;

  if (pin > 14)
    return (nts::Tristate::FALSE);
  if (_pins[pin] == UNUSED || _links[pin] == NULL)
    return (nts::Tristate::UNDEFINED);
  if (_pins[pin] == OUTPUT && _links[pin] != NULL)
    {
      if (pin == 3 || pin == 10)
        {
          if (_links[pin - 1] == NULL || _links[pin - 2] == NULL)
            return (nts::Tristate::UNDEFINED);
          i1 = _links[pin - 1]->Compute(1);
          i2 = _links[pin - 2]->Compute(1);
        }
      else
        {
          if (_links[pin + 1] == NULL || _links[pin + 2] == NULL)
            return (nts::Tristate::UNDEFINED);
          i1 = _links[pin + 1]->Compute(1);
          i2 = _links[pin + 2]->Compute(1);
        }
      if (i1 == nts::Tristate::UNDEFINED)
        {
	  std::ostringstream oss;
          oss << "Cannot compute " << _name << ": input pins states are UNDEFINED";
          throw ComputeError(oss.str());
        }
      _links[pin]->SetState((nts::Tristate)(i1 || i2));
    }
  return (nts::Tristate::TRUE);  
}

void		Chipset4001::SetLink(size_t from, nts::IComponent &cmp, size_t to)
{
  Link        *p;
  std::ostringstream oss;
  oss << "SetLink on 4001: pin " << from;

  if (from > _pinNbr)
    {
      oss << " does not exists.";
      throw LinkError(oss.str());
    }
  if (to != 0)
    {
      if (static_cast<AComponent *>(&cmp)->getType() == "output")
        {
          if (_pins[from] != PinTypes::OUTPUT)
            {
              oss << "trying to link a type output on a non output pin";
              throw LinkError(oss.str());
            }
          _links[from] = static_cast<AComponent*>(&cmp);
        }
      else if (static_cast<AComponent *>(&cmp)->getType() == "input")
        {
          if (_pins[from] != PinTypes::INPUT)
            {
              oss << "trying to link a type input on a non input pin";
              throw LinkError(oss.str());
            }
          _links[from] = static_cast<AComponent*>(&cmp);
        }
      else
        {
          p = new Link();
          _links[from] = p;
          p->SetLink(1, cmp, to);
        }
    }
  else
    {
      _links[from] = static_cast<AComponent*>(&cmp);
    }
}

void		Chipset4001::Dump() const
{
  std::cout << _name << std::endl;
  std::cout << "Chipset4001:" <<std::endl;
  for(size_t i = 1; i < _pinNbr; ++i)
    {
      nts::Tristate     state;

      if (_links[i] != NULL)
        {
          state = _links[i]->Compute(1);
          if (state == nts::Tristate::TRUE)
	    std::cout << "\t-pin " << i << ": TRUE" << std::endl;
          else if (state == nts::Tristate::FALSE)
	    std::cout << "\t-pin " << i << ": FALSE" << std::endl;
          else
	    std::cout << "\t-pin " << i << ": UNDEFINED" << std::endl;
        }
      else
	std::cout << "\t-pin " << i << ": NOT_LINKED" << std::endl;
    }
  
}

void		Chipset4001::SetState(nts::Tristate state)
{
  static_cast<void>(state);
}

AComponent	*Create4001(const std::string &name)
{
  return (new Chipset4001(name));
}
