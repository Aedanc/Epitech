//
// main.cpp for spider in /home/nicolas/Projects/C++/cpp_spider/server
// 
// Made by nicolas
// Login   <nicolas.giacomarosa@epitech.eu>
// 
// Started on  Thu Sep 28 11:18:12 2017 nicolas
// Last update Sun Oct  8 15:54:32 2017 nicolas
//

#include	<string>
#include	<iostream>
#include	"NetworkHandler.hpp"
#include	"Command.hpp"

int		main(int ac, char **av)
{
  NetworkHandler	network;
  Command		command(network);
  std::string		line;

  (void)ac;
  (void)av;
  std::getline(std::cin, line);
  while (1)
    {
      if (line.size() == 0);
      else if (command.call(line) == 1)
	return (0);
      std::getline(std::cin, line);
    }
  return (0);
}
