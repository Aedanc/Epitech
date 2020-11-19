//
// Chipset4040.cpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/sources
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Thu Feb 23 11:29:31 2017 Laurent QUERSIN
// Last update Sat Mar  4 00:45:44 2017 Laurent QUERSIN
//

#include "Chipset4040.hpp"

Chipset4040::Chipset4040(const std::string &name)
{
  _type = "4040";
  _name = name;
  _pinNbr = 17;
  for (size_t i = 0; i < _pinNbr; ++i)
      _links.push_back(NULL);
}

Chipset4040::~Chipset4040()
{
}

nts::Tristate	Chipset4040::Compute(size_t pin)
{
  std::ostringstream oss;

  static_cast<void>(pin);
  for (size_t i = 1; i < 16; ++i)
    {
      if (i != 8 && _pins[i] == PinTypes::INPUT && _links[i] != NULL && _links[i]->Compute(1) == nts::Tristate::UNDEFINED)
	{
	  oss << "cannot compute " << _name << ":inputs states are UNDEFINED.";
	  throw ComputeError(oss.str());
	}
      else if (i != 8 && _links[i] == NULL)
	{
	  oss << "cannot compute " << _name << " not all pins are connected.";
	  throw ComputeError(oss.str());
	}
    }

  if (_links[10]->Compute(1) == nts::Tristate::FALSE && _lastState == nts::Tristate::TRUE)
    {
      nts::Tristate res = nts::Tristate::TRUE;

      for(size_t i = 1; i <= 12; ++i)
        {
          if (_ordered[i]->Compute(1) == nts::Tristate::UNDEFINED)
            _ordered[i]->SetState(nts::Tristate::FALSE);
          if (res == nts::Tristate::TRUE)
            {
              if (_ordered[i]->Compute(1) == nts::Tristate::FALSE)
                {
                  _ordered[i]->SetState(nts::Tristate::TRUE);
                  res = nts::Tristate::FALSE;
                }
              else if (_ordered[i]->Compute(1) == nts::Tristate::TRUE)
                {
                  _ordered[i]->SetState(nts::Tristate::FALSE);
                }
            }
        }
    }
  if (_links[11]->Compute(1) == nts::Tristate::TRUE)
    {
      for(size_t i = 1; i <= 12; ++i)
        {
          _ordered[i]->SetState(nts::Tristate::FALSE);
        }
    }
  _lastState = _links[10]->Compute(1);

  return (nts::Tristate::FALSE);

}

void		Chipset4040::SetLink(size_t from, nts::IComponent &cmp, size_t to)
{
  Link        *p;
  std::ostringstream oss;
  oss << "SetLink on 4040: pin " << from;

  if (from >= _pinNbr)
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
	  _ordered[_order[from]] = _links[from];
        }
      else if (static_cast<AComponent *>(&cmp)->getType() == "input")
        {
          if (_pins[from] != PinTypes::INPUT)
            {
              oss << "trying to link a type input on a non input pin";
              throw LinkError(oss.str());
            }
          _links[from] = static_cast<AComponent*>(&cmp);
	  _ordered[_order[from]] = _links[from];
        }
      else
        {
          p = new Link();
          _links[from] = p;
	  _ordered[_order[from]] = p;
          p->SetLink(1, cmp, to);
        }
    }
  else
    {
      _links[from] = static_cast<AComponent*>(&cmp);
      _ordered[_order[from]] = _links[from];
    }
}

void		Chipset4040::Dump() const
{
  std::cout << _name << std::endl;
  std::cout << "Chipset4040:" <<std::endl;
  for(size_t i = 1; i <= _pinNbr; ++i)
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

void		Chipset4040::SetState(nts::Tristate state)
{
  static_cast<void>(state);
}

AComponent	*Create4040(const std::string &name)
{
  return (new Chipset4040(name));
}
