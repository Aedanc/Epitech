//
// main.cpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/sources
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Thu Feb 16 10:08:17 2017 Laurent QUERSIN
// Last update Thu Feb 16 10:08:20 2017 Laurent QUERSIN
//

#include		"NanoTek.hpp"
#include		"Error.hh"

int			main(int argc, char **argv)
{
  NanoTek		nano(argc, argv);

  nano.run();
  return (0);
}
