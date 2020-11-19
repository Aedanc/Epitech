//
// Elf.cpp for elf in /home/dourches/Epitech/Seconde/Piscine/cpp_santa/includes
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Sat Jan 14 21:34:11 2017 dourches
// Last update Sun Jan 15 09:27:45 2017 Hugo Willaume
//

# include	"Elf.hh"

Elf::Elf(ITable *table, IConveyorBelt *belt)
{
  Table = table;
  Belt = belt;
  RightHand = NULL;
  LeftHand = NULL;
}

Elf::~Elf()
{
  delete (Table);
  delete (Belt);
}

Elf::Elf(Elf const &elf) : Table(elf.Table), Belt(elf.Belt), RightHand(elf.RightHand), LeftHand(elf.LeftHand)
{
}

Elf	&Elf::operator=(Elf const &other)
{
  Table = other.Table;
  Belt = other.Belt;
  RightHand = other.RightHand;
  LeftHand = other.LeftHand;
  return *this;
}

void	Elf::ElfWrap()
{
  RightHand = Table->Take();
  if (RightHand == NULL)
    return ;
  if (RightHand->getTitle() == "Box" || RightHand->getTitle() == "Gift paper")
    {
      LeftHand = Table->Take("Teddy", ITable::BY_CLASS);
      if (LeftHand == NULL)
	{
	  LeftHand = Table->Take("Little Pony", ITable::BY_CLASS);
	  if (LeftHand == NULL)
	      return ;
	}
      ((AWrap *)RightHand)->wrapMeThat(LeftHand);
      Belt->put(RightHand);
      Belt->out();
    }
  else
    {
      LeftHand = Table->Take("Box", ITable::BY_CLASS);
      if (LeftHand == NULL)
	{
	  LeftHand = Table->Take("giftPaper", ITable::BY_CLASS);
	  if (LeftHand == NULL)
	      LeftHand = Belt->in();
	}
      ((AWrap *)LeftHand)->wrapMeThat(RightHand);
      Belt->put(LeftHand);
      Belt->out();
    }
}
