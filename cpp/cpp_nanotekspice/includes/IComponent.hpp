//
// IComponent.hpp for NanoTekSPice in /home/quersi_l/rendu/cpp_nanotekspice/include
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Tue Feb 14 11:49:59 2017 Laurent QUERSIN
// Last update Fri Mar  3 12:14:58 2017 Laurent QUERSIN
//


#ifndef __ICOMPONENT_HPP__
# define __ICOMPONENT_HPP__

#include	<iostream>

namespace nts
{
  enum Tristate
    {
      UNDEFINED = (-true),
      TRUE = true,
      FALSE = false
    };

  class IComponent
  {
  public:
    virtual ~IComponent(void) { }
    virtual nts::Tristate	Compute(size_t) = 0;
    virtual void		SetLink(size_t, nts::IComponent &, size_t) = 0;
    virtual void		Dump(void) const = 0;
  };
}

#endif
