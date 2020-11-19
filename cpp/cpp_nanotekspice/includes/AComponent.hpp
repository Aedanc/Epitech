//
// AComponent.hpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/includes
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Thu Feb 23 13:36:13 2017 Laurent QUERSIN
// Last update Fri Mar  3 21:18:04 2017 Laurent QUERSIN
//

#ifndef  ACOMPONENT_HPP__
# define ACOMPONENT_HPP__

#include <vector>

#include "IComponent.hpp"

class AComponent : public nts::IComponent
{
protected:
  AComponent();

protected:
  std::string			_name;
  std::string			_type;
  size_t			_pinNbr;
  std::vector<AComponent*>	_links;

public:
  size_t			depth;
  std::string			lastVisitedBy;

public:
  ~AComponent() {}
  virtual nts::Tristate		Compute(size_t pin = 1) = 0;
  virtual void			SetLink(size_t, nts::IComponent &, size_t) = 0;
  virtual void			Dump() const = 0;
  virtual void			SetState(nts::Tristate) = 0;
  std::string			getName() const;
  std::string			getType() const;
  size_t			getPinNbr() const;
  AComponent			*getLinkedCmp(size_t) const;
};

#endif
