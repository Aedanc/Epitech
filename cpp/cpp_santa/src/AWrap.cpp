//
// AWrap.cpp for awrap in /home/dourches/Epitech/Seconde/Piscine/cpp_santa/includes
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Sat Jan 14 14:10:07 2017 dourches
// Last update Sun Jan 15 09:42:22 2017 Hugo Baldassin
//

# include	"AWrap.hh"

AWrap::AWrap(std::string class_name, std::string title) : AObject(class_name, title),
							  _empty(true)
{
  _gift = NULL;
}

AWrap::~AWrap()
{
}

AWrap::AWrap(AWrap const &wrap) : AObject(wrap._class, wrap._title),
				  _empty(wrap._empty), _gift(wrap._gift)
{
}

AWrap	&AWrap::operator=(AWrap const &wrap)
{
  _class = wrap._class;
  _empty = wrap._empty;
  _gift = wrap._gift;
  _title = wrap._title;
  return *this;
}

bool	AWrap::IsEmpty() const
{
  return (_empty);
}

void	AWrap::isTaken() const
{
  std::cout << "whistles while working" << std::endl;
}

IObject	*AWrap::getGift() const
{
  return (_gift);
}
