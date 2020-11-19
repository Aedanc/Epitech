//
// Box.cpp for Box in /home/dourches/Epitech/Seconde/Piscine/cpp_santa/includes
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Sat Jan 14 14:33:32 2017 dourches
// Last update Sun Jan 15 09:29:39 2017 Hugo Willaume
//

# include	"Box.hh"

Box::Box() : AWrap("Box", "Gift box")
{
  is_open = true;
}


Box::~Box()
{
}

Box::Box(Box const &box) : AWrap(box._class, box._title), is_open(box.is_open)
{
}

Box &Box::operator=(Box const &box)
{
  _class = box._class;
  _empty = box._empty;
  _gift = box._gift;
  _title = box._title;
  is_open = box.is_open;
  return *this;
}

bool	Box::IsEmpty() const
{
  return (_empty);
}

bool	Box::IsOpen() const
{
  return (is_open);
}

void	Box::wrapMeThat(IObject* &object)
{
  if (!IsEmpty())
    return;
  _empty = false;
  is_open = false;
  std::swap(object, _gift);
  std::cout << "tuuuut tuuut tuut" << std::endl;
}


IObject *Box::clone() const
{
  return new Box();
}
