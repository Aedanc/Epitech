//
// IConveyorBelt.hh for  in /home/fortevg/rendu/piscine_cpp/cpp_santa/includes
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Sat Jan 14 20:58:27 2017 Gabriel Forteville
// Last update Sun Jan 15 09:47:24 2017 Hugo Willaume
//


#ifndef		__ICONVEYORBELT_HH_
# define	__ICONVEYORBELT_HH_

# include	"IObject.hh"
# include	"AWrap.hh"

class IConveyorBelt
{
  private:

  protected:

  public:
  virtual ~IConveyorBelt() {};

  virtual IObject *take() const = 0;
  virtual void put(IObject* &) = 0;
  virtual void out() = 0;
  virtual AWrap *in() const = 0;
  virtual IObject *look() const = 0;
};

#endif /* !__ICONVEYORBELT_HH_ */
