//
// Command.cpp for spider in /home/nicolas/Projects/C++/cpp_spider/server
// 
// Made by nicolas
// Login   <nicolas.giacomarosa@epitech.eu>
// 
// Started on  Tue Oct  3 16:05:41 2017 nicolas
// Last update Mon Oct  9 22:25:58 2017 nicolas
//

#include	"Command.hpp"

Command::Command(NetworkHandler &network) : _network(network)
{
  std::string		str("Spider");
  
  _functionMap.insert(std::make_pair(static_cast<std::string>("STOP"), &Command::stop));
  _functionMap.insert(std::make_pair(static_cast<std::string>("LIST"), &Command::list));
  _functionMap.insert(std::make_pair(static_cast<std::string>("SEND"), &Command::send_cmd));
  _functionMap.insert(std::make_pair(static_cast<std::string>("EXPORT"), &Command::export_db));
  _db.createEntry(str);
}

int		Command::stop(const std::string &cmd)
{
  (void)cmd;
  std::cout << "Stopping server" << std::endl;
  _network.stop_server();
  return (1);
}

int		Command::list(const std::string &cmd)
{
  (void)cmd;
  _network.print_client_list();
  return (0);
}

bool		BothAreSpaces(char lhs, char rhs)
{
  return (lhs == rhs) && (lhs == ' ');
}
	
bool		file_exist(const std::string &name)
{
  if (std::ifstream(name.c_str()))
    {
      std::cerr << "[ERROR] The file already exist" << std::endl;     
      return (false);
    }
  return (true);
}


int		Command::export_db(const std::string &cmd)
{
  std::string			copy = cmd;
  std::string::iterator		new_end = std::unique(copy.begin(), copy.end(), BothAreSpaces);
  std::size_t			found = copy.find(' ');
  int				it = 0;

  if (copy.find('\t') != std::string::npos)
    {
      std::cerr << "[ERROR] \\t isn't handle" << std::endl;
      return (0);
    }
  copy.erase(new_end, copy.end());
  if (copy.back() == ' ')
    copy.pop_back();
  while (found != std::string::npos)
    {
      found = copy.find(' ', found + 1);
      it++;
    }
  found = copy.find(' ');
  if (it > 3 || it == 0)
    {
      std::cerr << "[ERROR] Invalid command" << std::endl;
      return (0);
    }
  else if (it == 2)
    {
      const auto	pos = copy.find_last_of(' ');
      std::string	firstWord = copy.substr(found + 1, pos - (copy.find(' ') + 1));
      std::string	secondWord = copy.substr(pos + 1);
      int		id;

      if (!file_exist(firstWord))
	return (0);
      try
	{
	  id = stoi(secondWord);
	  if (id < 0)
	    {
	      std::cerr << "[ERROR] Invalid id argument, please enter a positive number" << std::endl;
	      return (0);
	    }
	}
      catch (std::invalid_argument& e)
	{
	  std::cerr << "[ERROR] Invalid id argument, please enter a number" << std::endl;
	  return (0);
	}
      catch (std::out_of_range& e)
	{
	  std::cerr << "[ERROR] Out of range id" << std::endl; 
	  return (0);
	}
      _db.expor(firstWord, id);
    }
  else   
    {
      std::string	firstWord = copy.substr(copy.find(' ') + 1);

      if (!file_exist(firstWord))
	return (0);
      _db.expor(firstWord);
    }
  return (0);
}

int		Command::send_cmd(const std::string &cmd)
{
  std::cout << cmd << std::endl;
  return (0);
}

std::string	Command::getFirstCommand(const std::string &cmd)
{
  std::string	firstWord = cmd.substr(0, cmd.find(' '));

  return (firstWord);
}

int		Command::call(std::string &cmd)
{
  std::string		cmdFirstPart = Command::getFirstCommand(cmd);
  FunctionPointer	functionPtr = _functionMap[cmdFirstPart];

  if (functionPtr == 0)
    {
      std::cout << "[ERROR] This command doesn't exist" << std::endl;
      return (0);
    }
  return ((this->*functionPtr)(cmd));
}
