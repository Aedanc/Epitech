//
// Error.cpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/sources
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Thu Feb 16 09:45:23 2017 Laurent QUERSIN
// Last update Thu Feb 16 09:45:24 2017 Laurent QUERSIN
//


#include	"Error.hh"

ParsingError::ParsingError(const std::string &error) : msg(error.c_str())
{
}

ParsingError::~ParsingError() throw()
{
}

const char	*ParsingError::what() const throw()
{
  return (this->msg);
}

ComputeError::ComputeError(const std::string &error) : msg(error.c_str())
{
}

ComputeError::~ComputeError() throw()
{
}

const char	*ComputeError::what() const throw()
{
  return (this->msg);
}

LinkError::LinkError(const std::string &error) : msg(error.c_str())
{
}

LinkError::~LinkError() throw()
{
}

const char	*LinkError::what() const throw()
{
  return (this->msg);
}
