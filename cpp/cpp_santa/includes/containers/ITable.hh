//
// ITable.hh for  in /home/hurlu/rendu/cpp_santa/containers
// 
// Made by Hugo Willaume
// Login   <willau_h@epitech.net>
// 
// Started on  Sat Jan 14 18:43:18 2017 Hugo Willaume
// Last update Sun Jan 15 03:50:28 2017 dourches
//

#ifndef		ITABLE_HH_
# define	ITABLE_HH_

#include <string>
#include "IObject.hh"


class ITable{
private:


protected:
  virtual void Collapse() = 0;
  
public:
  
  virtual ~ITable() {};

    enum TakeFilter{
    BY_CLASS,
    BY_TITLE
  };
  
  virtual std::string **Look() const = 0;
  virtual void Put(IObject* &obj) = 0;
  virtual IObject *Take() = 0;
  virtual IObject *Take(int n) = 0;
  virtual IObject *Take(std::string filter, ITable::TakeFilter type) = 0;
};

#endif		/* ITABLE_HH_ */
