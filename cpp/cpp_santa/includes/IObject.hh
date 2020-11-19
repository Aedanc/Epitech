//
// IObject.hh for  in /home/hurlu/rendu/cpp_santa
// 
// Made by Hugo Willaume
// Login   <willau_h@epitech.net>
// 
// Started on  Sat Jan 14 13:38:37 2017 Hugo Willaume
// Last update Sun Jan 15 00:23:34 2017 Hugo Willaume
//

#ifndef		IOBJECT_HH_
# define	IOBJECT_HH_

#include <string>

class IObject{
private:


protected:


public:
  virtual ~IObject() {};
  virtual const std::string & getClass() const = 0;
  virtual const std::string & getTitle() const = 0;
  virtual void isTaken() const = 0;
  virtual IObject *clone() const = 0;

};

#endif		/* IOBJECT_HH_ */
