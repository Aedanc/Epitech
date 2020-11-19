
#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>
#include <exception>

class NasaError : public std::exception
{
public:
  NasaError(std::string const &message,
	    std::string const &component = "Unknown");
  virtual ~NasaError() throw();
  virtual const char *what() const throw();
  virtual std::string const &getComponent() const;

protected:
  std::string _message;
  std::string component;
};

class MissionCriticalError : public NasaError
{
    public: 
        MissionCriticalError(std::string const &message,
                std::string const &component = "Unknown");
  ~MissionCriticalError() throw();
};

class LifeCriticalError  : public NasaError
{
    public:
        LifeCriticalError(std::string const &message,
                std::string const &component = "Unknown");
  ~LifeCriticalError() throw();
};

class UserError  : public NasaError
{
    public:
        UserError(std::string const &message,
                std::string const &component = "Unknown");
  ~UserError() throw();
};

class CommunicationError  : public NasaError
{
    public:
        CommunicationError(std::string const &message);
  ~CommunicationError() throw();
};

#endif
