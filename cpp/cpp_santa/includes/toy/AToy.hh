//
// AToy.hh for  in /home/fortevg/rendu/piscine_cpp/cpp_santa/includes/toy
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Sat Jan 14 13:59:17 2017 Gabriel Forteville
// Last update Sat Jan 14 22:41:39 2017 Hugo Willaume
//

#ifndef		__ATOY_HH_
# define	__ATOY_HH_

# include	<iostream>
# include	<string>
# include	"AObject.hh"

class AToy : public AObject
{
private:

protected:

public:
  AToy(std::string title, std::string name);
  AToy(AToy const& other);
  virtual ~AToy();

  virtual void isTaken() const = 0;
  virtual IObject *clone() const = 0;

  AToy& operator=(AToy const& other);
};		/* Atoy */

#endif		/* __ATOY_HH_  */
