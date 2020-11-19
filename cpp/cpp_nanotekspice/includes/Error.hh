//
// Error.hh for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/sources
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Thu Feb 16 09:45:41 2017 Laurent QUERSIN
// Last update Thu Feb 16 09:45:42 2017 Laurent QUERSIN
//

#ifndef ERROR_HH_
# define ERROR_HH_

#include	<stdexcept>
#include	<sstream>

class	ParsingError : public std::exception
{
private:
  const	char	*msg;

public:
  ParsingError(const std::string &);
  ~ParsingError() throw();
  const	char	*what() const throw();
};

class	ComputeError : public std::exception
{
private:
  const	char	*msg;

public:
  ComputeError(const std::string &);
  ~ComputeError() throw();
  const	char	*what() const throw();
};

class	LinkError : public std::exception
{
private:
  const	char	*msg;

public:
  LinkError(const std::string &);
  ~LinkError() throw();
  const	char	*what() const throw();
};

#endif
