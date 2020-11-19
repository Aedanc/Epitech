//
// ConveyorBelt.hh for  in /home/fortevg/rendu/piscine_cpp/cpp_santa/includes
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Sat Jan 14 23:12:40 2017 Gabriel Forteville
// Last update Sun Jan 15 09:46:51 2017 Hugo Willaume
//

#ifndef __CONVEYORBELT_HH_
#define __CONVEYORBELT_HH_

#include	"IConveyorBelt.hh"

class ConveyorBelt : public IConveyorBelt
{
private:

protected:
  IObject *_item;

public:
  ConveyorBelt();
  ConveyorBelt(ConveyorBelt const& other);
  virtual ~ConveyorBelt();

  virtual IObject *take() const;
  virtual void put(IObject* &);
  virtual void out();
  virtual AWrap *in() const;
  virtual IObject *look() const;

  ConveyorBelt &operator=(ConveyorBelt const& other);
};

#endif
