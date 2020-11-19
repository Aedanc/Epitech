//
// Elf.hh for elf in /home/dourches/Epitech/Seconde/Piscine/cpp_santa/includes
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Sat Jan 14 21:17:15 2017 dourches
// Last update Sun Jan 15 08:22:35 2017 Hugo Willaume
//

#ifndef		ELF_HH_
# define	ELF_HH_

# include	"IElf.hh"
# include	"ConveyorBelt.hh"
# include	"TablePeNoel.hh"

class Elf : public IElf
{
private:
  ITable *Table;
  IConveyorBelt *Belt;
  IObject *RightHand;
  IObject *LeftHand;

protected:

public:
  Elf(ITable *, IConveyorBelt *);
  ~Elf();
  Elf(Elf const &);
  Elf &operator=(Elf const &);
  virtual void ElfWrap();
};

#endif		/* !ELF_HH_ */
