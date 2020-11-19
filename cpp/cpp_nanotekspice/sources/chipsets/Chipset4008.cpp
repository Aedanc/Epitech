//
// Chipset4008.cpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/sources
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Thu Feb 23 11:29:31 2017 Laurent QUERSIN
// Last update Sat Mar  4 00:45:36 2017 Laurent QUERSIN
//

#include "Chipset4008.hpp"

Chipset4008::Chipset4008(const std::string &name)
{
  _type = "4008";
  _name = name;
  _pinNbr = 17;
  for (size_t i = 0; i < _pinNbr; ++i)
      _links.push_back(NULL);
}

Chipset4008::~Chipset4008()
{
}

nts::Tristate	Chipset4008::Compute(size_t pin)
{
  std::ostringstream oss;

  (void) pin;
  for (size_t i = 1; i < 16; ++i)
    {
      if (i != 8 && _pins[i] == PinTypes::INPUT && _links[i] != NULL && _links[i]->Compute(1) == nts::Tristate::UNDEFINED)
	{
	  oss << "cannot compute " << _name <<": inputs states are UNDEFINED";
	    throw ComputeError(oss.str());
	}
      else if (i != 8 && _links[i] == NULL)
	{
	  oss <<"cannot compute " << _name << ": not all pins are connected.";
	    throw ComputeError(oss.str());
	}
    }

  nts::Tristate a[4];
  nts::Tristate b[4];
  nts::Tristate cin = _links[9]->Compute(1);

  a[0] = _links[7]->Compute(1);
  a[1] = _links[5]->Compute(1);
  a[2] = _links[3]->Compute(1);
  a[3] = _links[1]->Compute(1);

  b[0] = _links[6]->Compute(1);
  b[1] = _links[4]->Compute(1);
  b[2] = _links[2]->Compute(1);
  b[3] = _links[15]->Compute(1);

  for (size_t i = 0; i < 4; ++i)
    {
      int res = a[i] + b[i] + cin;

      if (res == 0)
        _links[10 + i]->SetState(nts::Tristate::FALSE);
      else if (res == 1)
        {
          _links[10 + i]->SetState(nts::Tristate::TRUE);
          cin = nts::Tristate::FALSE;
        }
      else if (res == 2)
        {
          _links[10 + i]->SetState(nts::Tristate::FALSE);
          cin = nts::Tristate::TRUE;
        }
      else if (res == 3)
        {
          _links[10 + i]->SetState(nts::Tristate::TRUE);
          cin = nts::Tristate::TRUE;
        }
    }
  _links[14]->SetState(cin);
  return (nts::Tristate::FALSE);
}

void		Chipset4008::SetLink(size_t from, nts::IComponent &cmp, size_t to)
{
  Link        *p;
  std::ostringstream oss;
  oss << "SetLink on 4001: pin " << from;

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

void		Chipset4008::Dump() const
{
  std::cout << _name << std::endl;
  std::cout << "Chipset4008:" <<std::endl;
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

void		Chipset4008::SetState(nts::Tristate state)
{
  static_cast<void>(state);
}

AComponent	*Create4008(const std::string &name)
{
  return (new Chipset4008(name));
}
