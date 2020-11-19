//
// NanoTek.cpp for nanotekspice in /home/quersi_l/rendu/2015/cpp_nanotekspice/source
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Wed Feb 15 10:02:38 2017 Laurent QUERSIN
// Last update Thu Feb 23 16:41:04 2017 Laurent QUERSIN
//

#include		"NanoTek.hpp"
#include		"ParserLexer.hpp"
#include		"Error.hh"

NanoTek::NanoTek(int argc, char **argv)
{
  _runningSim = false;
  _argv = argv;
  _argc = argc;
}

NanoTek::~NanoTek()
{
}

void			NanoTek::findNTS(const std::string &fileName)
{
  Circuit c;

  if ((fileName.find(".nts") != std::string::npos) && fileName[fileName.find(".nts") + 4] == '\0')
    {
      std::ifstream file(fileName, std::ios::in);
      
      if (file)
	{
	  t_ast_node		*root;
	  ParserLexer		parsing;
	  std::string		str;
	  
	  while (getline(file, str))
	    parsing.feed(str);
	  file.close();
	  root = parsing.createTree();
	  parsing.parseTree(*root);
	  c.sortCircuit();
	  return;
	}
      throw ParsingError("Can't open .nts file.");
    }
  throw ParsingError("Can't find .nts file.");
}

void			NanoTek::run()
{
  std::string	str;

  if (this->_argc >= 2)
    {
      str = this->_argv[1];
      try
	{
	  this->findNTS(str);
	}
      catch (const std::exception &Error)
	{
	  std::cout << "Error: error while handling .nts : " << Error.what() << std::endl;
	  return;
	}
      this->actions();
    }
  else
    std::cout << "Usage: ./nanotekspice *.nts {input=value}" << std::endl;
}

void			NanoTek::actions()
{
  std::string		str;
  bool			looper = true;;
  CommandParser		parser;
  
  std::signal(SIGINT, myhandler);
  for (int i = 2; i < this->_argc; ++i)
    {
      str = this->_argv[i];
      looper = parser.parseLine(str);
    }
  while (looper == true)
    {
      try
	{
	  std::getline(std::cin, str);
	  looper = parser.parseLine(str);
	}
      catch (const std::exception &Error)
	{
	  std::cout << "Error: " << Error.what() << std::endl;
	}
    }
}

void			myhandler(int s)
{
  (void) s;
  return;
}
