//
// IElf.hh for ielf in /home/dourches/Epitech/Seconde/Piscine/cpp_santa/includes
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Sat Jan 14 20:53:09 2017 dourches
// Last update Sun Jan 15 04:03:45 2017 dourches
//

#ifndef		IELF_HH_
# define	IELF_HH_

# include	"IObject.hh"
# include	"AWrap.hh"
# include	"IConveyorBelt.hh"

class		IElf
{
private:

  protected:
  
  public:
  virtual ~IElf() {};
  virtual void ElfWrap() = 0;
};


#endif		/* !IELF_HH_ */
