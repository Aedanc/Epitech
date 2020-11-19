//
// CommandParser.hpp for nanotekspice in /home/rik-garett/rendu/cpp_nanotekspice
// 
// Made by Clément Liagre
// Login   <liagre_c@epitech.net>
// 
// Started on  Tue Feb 23 09:16:26 2016 Clément Liagre
// Last update Fri Feb 17 13:52:47 2017 Laurent QUERSIN
//


# ifndef COMMANDPARSER_HPP__
# define COMMANDPARSER_HPP__

#include "Parser.hpp"

class                   CommandParser
{

public:
  CommandParser();
  ~CommandParser();

public:
  void			setInput(std::string &);
  void			display();
  void			simulate();
  void			dump();
  void			loop();

public:
  bool                  checkAlphaNum(const std::string &);
  bool			parseLine(std::string &);
  void		        cleanStr(std::string &);
};


#endif
