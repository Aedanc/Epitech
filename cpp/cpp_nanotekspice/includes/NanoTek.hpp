//
// NanoTek.hpp for nanotekspice in /home/rik-garett/rendu/cpp_nanotekspice
// 
// Made by Clément Liagre
// Login   <liagre_c@epitech.net>
// 
// Started on  Tue Feb  9 09:51:43 2016 Clément Liagre
// Last update Thu Feb 16 09:48:49 2017 Laurent QUERSIN
//

#include	<algorithm>
#include	<iostream>
#include	<fstream>
#include	<string>
#include	<list>
#include	<map>

#include	<csignal>

#include	"IComponent.hpp"
#include	"ParserLexer.hpp"
#include	"CommandParser.hpp"

class		NanoTek
{
private:
  bool						_runningSim;
  char						**_argv;
  int						_argc;
  std::map<std::string, std::string>		inputs;

public:
  NanoTek(int, char **);
  ~NanoTek();
  void						run();
  void						actions();
  void						findNTS(const std::string &);
  void						isInput(std::string &);
};

void						myhandler(int);
