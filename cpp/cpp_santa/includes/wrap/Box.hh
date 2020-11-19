//
// Box.hh for box in /home/dourches/Epitech/Seconde/Piscine/cpp_santa/includes
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Sat Jan 14 14:24:24 2017 dourches
// Last update Sat Jan 14 22:41:04 2017 Hugo Willaume
//

#ifndef		BOX_HH_
# define	BOX_HH_

# include	"AWrap.hh"

class Box : public AWrap
{
private:
  bool is_open;
protected:

public:
  Box();
  Box(Box const &);
  Box &operator=(Box const &);
  virtual ~Box();

  virtual IObject *clone() const;
  virtual void wrapMeThat(IObject* &);
  virtual bool IsEmpty() const;
  bool	IsOpen() const;
 };

#endif
