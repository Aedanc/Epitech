//
// ConveyorBelt.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_santa
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Sat Jan 14 23:54:30 2017 Gabriel Forteville
// Last update Sun Jan 15 09:46:55 2017 Hugo Willaume
//

# include	"ConveyorBelt.hh"
# include	"Box.hh"
# include	"GiftPaper.hh"
# include	<algorithm>

ConveyorBelt::ConveyorBelt()
{
  _item = NULL;
}

ConveyorBelt::ConveyorBelt(ConveyorBelt const& other)
{
  _item = other._item;
}

ConveyorBelt::~ConveyorBelt()
{
}

IObject *ConveyorBelt::take() const
{
  return (_item);
}

void ConveyorBelt::put(IObject* &other)
{
  if (_item == NULL)
    std::swap(_item, other);
}

void ConveyorBelt::out()
{
  if (_item != NULL)
    {
      if (((AWrap *)_item)->getGift() != NULL)
      	delete(((AWrap *)_item)->getGift());
      delete(_item);
      _item = NULL;
    }
}

AWrap *ConveyorBelt::in() const
{
  int choice;
  AWrap *wrap;

  choice = random() % 2;
  if (choice == 0)
    wrap  = new Box();
  else
    wrap = new GiftPaper();

  return (wrap);
}

IObject *ConveyorBelt::look() const
{
  if (_item != NULL)
    return (_item);
  return (NULL);
}
