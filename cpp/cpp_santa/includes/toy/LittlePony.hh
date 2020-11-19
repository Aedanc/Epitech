//
// LittlePony.hh for LittlePony in /home/baldas/Prog/repos/tek2/piscine/rush/cpp_santa/src
// 
// Made by Hugo Baldassin
// Login   <hugo.baldassin@epitech.eu>
// 
// Started on  Sat Jan 14 15:47:18 2017 Hugo Baldassin
// Last update Sat Jan 14 22:41:50 2017 Hugo Willaume
//

#ifndef LITTLEPONY_HH_
# define LITTLEPONY_HH_

# include <string>
# include "AToy.hh"

class LittlePony : public AToy {
public:
  LittlePony(std::string const& title);
  LittlePony(LittlePony const& littlePony);
  LittlePony& operator=(LittlePony const& littlePony);
  ~LittlePony();

  virtual void isTaken() const;
  virtual IObject *clone() const ;
};

#endif /* !LITTLEPONY_HH_ */
