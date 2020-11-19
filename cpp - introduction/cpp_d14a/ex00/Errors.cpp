//
// Error.cpp for  in /home/fortevg/rendu/piscine_cpp/cpp_d14a/ex00
// 
// Made by Gabriel Forteville
// Login   <fortev_g@epitech.net>
// 
// Started on  Tue Jan 17 18:04:35 2017 Gabriel Forteville
// Last update Tue Jan 17 22:24:46 2017 Gabriel Forteville
//

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component)
{
  this->component = component;
  this->_message = message;
}

const char *NasaError::what() const throw()
{
  return _message.c_str();
}

NasaError::~NasaError() throw() {}

std::string const& NasaError::getComponent() const
{
  return component;
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component): NasaError(message, component) {}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component): NasaError(message, component) {}

UserError::UserError(std::string const &message, std::string const &component): NasaError(message, component) {}

CommunicationError::CommunicationError(std::string const &message): NasaError(message, "CommunicationDevice") {}

MissionCriticalError::~MissionCriticalError() throw() {}

LifeCriticalError::~LifeCriticalError() throw() {}

UserError::~UserError() throw() {}

CommunicationError::~CommunicationError() throw() {}
