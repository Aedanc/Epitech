//
// AWrap.hh for AWrap in /home/dourches/Epitech/Seconde/Piscine/cpp_santa/includes
// 
// Made by dourches
// Login   <martin.dourches@epitech.eu>
// 
// Started on  Sat Jan 14 13:57:50 2017 dourches
// Last update Sat Jan 14 22:39:14 2017 Hugo Willaume
//


#ifndef		AWRAP_HH_
# define	AWRAP_HH_

# include	<string>
# include	<iostream>
# include	<algorithm>
# include	"AObject.hh"
# include	"IObject.hh"

class AWrap : public AObject
{
private:

protected:
  bool _empty;
  IObject *_gift;

public:
  AWrap(std::string _class, std::string title);
  virtual ~AWrap();
  AWrap(AWrap const &);
  AWrap &operator=(AWrap const &);

  virtual void isTaken() const;
  virtual IObject *clone() const = 0;
  virtual void wrapMeThat(IObject* &) = 0;
  virtual bool IsEmpty() const;
  virtual IObject *getGift() const;
};

#endif		/* !AWRAP_HH_ */
