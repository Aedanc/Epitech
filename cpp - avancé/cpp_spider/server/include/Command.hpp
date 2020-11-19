//
// Command.hpp for spider in /home/nicolas/Projects/C++/cpp_spider/server
// 
// Made by nicolas
// Login   <nicolas.giacomarosa@epitech.eu>
// 
// Started on  Tue Oct  3 16:06:19 2017 nicolas
// Last update Sun Oct  8 23:18:04 2017 nicolas
//

#ifndef		_COMMAND_HPP_
# define	_COMMAND_HPP_

#include	<map>
#include	<iostream>
#include	<string>
#include	<fstream>
#include	"NetworkHandler.hpp"
#include	"sql/Database.hpp"

class		Command
{
private:
  NetworkHandler				&_network;
  typedef	int	(Command::*FunctionPointer)(const std::string &);
  std::map<std::string, FunctionPointer>	_functionMap;
  Database					_db;
  int						stop(const std::string &);
  int						list(const std::string &);
  int						send_cmd(const std::string &);
  int						export_db(const std::string &);
  std::string					getFirstCommand(const std::string &cmd);
public:
  Command(NetworkHandler &);
  ~Command(){}
  int						call(std::string &);
};

#endif		/*!_COMMAND_HPP_*/
