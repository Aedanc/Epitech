//
// CommandParser.cpp for nanotekspice in /home/rik-garett/rendu/cpp_nanotekspice
// 
// Made by Clément Liagre
// Login   <liagre_c@epitech.net>
// 
// Started on  Tue Feb 23 09:19:43 2016 Clément Liagre
// Last update Fri Feb 17 13:56:39 2017 Laurent QUERSIN
//

#include	"CommandParser.hpp"
#include	"NanoTek.hpp"
#include	"Error.hh"

// static const std::string  _commands[6]
// {
//   "=",
//     "display",
//     "simulate",
//     "dump",
//     "loop",
//     "exit"
//     };


CommandParser::CommandParser()
{
}

CommandParser::~CommandParser()
{
}

bool			CommandParser::parseLine(std::string &str)
{
  if (str.length() == 0)
    return (true);
  cleanStr(str);
  if (str.find('=') != std::string::npos)
    setInput(str);
  else if (str == "display")
    display();
  else if (str == "simulate")
    simulate();
  else if (str == "dump")
    dump();
  else if (str == "loop")
    loop();
  else if (str == "exit")
    return (false);
  return (true);
}

void			CommandParser::setInput(std::string &str)
{
  size_t pos;
  std::string name;
  std::string value;
  nts::Tristate state = nts::Tristate::UNDEFINED;
  Circuit c;

  pos = str.find("=");
  name = str.substr(0, pos);
  value = str.substr(pos + 1);

  if (name == "")
    throw ParsingError("Invalid assignation: name empty");
  if (checkAlphaNum(name) == false)
    throw ParsingError("Invalid assignation: name contains invalid characters");
  if (value != "0" && value != "1")
    throw ParsingError("Invalid assignation: state must be either 0 or 1");

  if (value == "0")
    state = nts::Tristate::FALSE;
  if (value == "1")
    state = nts::Tristate::TRUE;
  c.setInput(name, state);
}

bool                    CommandParser::checkAlphaNum(const std::string &str)
{
  std::string::size_type i = 0;

  while (i < str.length() && (std::isalnum(str[i]) || str[i] == ' '))
    i++;
  if (i != str.length())
    return (false);
  return (true);
}

void			CommandParser::loop()
{
  Circuit c;
  c.loop();
}

void			CommandParser::display()
{
  Circuit c;
  c.displayOutputs();
}

void			CommandParser::simulate()
{
  Circuit c;
  c.simulate();
}

void			CommandParser::dump()
{
  Circuit c;
  c.dump();
}


//CLEANING AND GETTERS FOR SUBSTREAMS

void                    CommandParser::cleanStr(std::string &str)
{
  size_t        i;

  while ((i = str.find("\t")) != std::string::npos)
    str.replace(i, 1, "");
  if ((i = str.find_first_not_of(" ")) != std::string::npos)
    str.replace(0, i, "");
  if ((i = str.find_last_not_of(" ")) != std::string::npos)
    str.replace(i + 1, str.length() - i, "");
  while ((i = str.find(" ")) != std::string::npos)
    str.replace(i, 1, "");
 if (str == " ")
    str = "";
}
