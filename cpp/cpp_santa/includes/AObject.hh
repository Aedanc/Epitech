//
// AObject.hh for  in /home/hurlu/rendu/cpp_santa/includes
// 
// Made by Hugo Willaume
// Login   <willau_h@epitech.net>
// 
// Started on  Sat Jan 14 13:41:27 2017 Hugo Willaume
// Last update Sun Jan 15 00:18:51 2017 Hugo Willaume
//

#ifndef		AOBJECT_HH_
# define	AOBJECT_HH_

#include "IObject.hh"
#include <string>

class AObject : public IObject {
private:


protected:
  std::string _class;
  std::string _title;

public:
  AObject(std::string _class, std::string _title);
  AObject(AObject const &other);
  AObject & operator=(AObject const &other);
  ~AObject();

  const std::string& getTitle() const;
  const std::string& getClass() const;
};

#endif		/* AOBJECT_HH_ */
