//
// ParserLexer.hpp for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice/source
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Wed Feb 10 10:27:07 2016 Laurent QUERSIN
// Last update Fri Feb 17 14:44:00 2017 Laurent QUERSIN
//

#ifndef PARSERLEXER_HPP__
# define PARSERLEXER_HPP__

#include "Circuit.hpp"	
#include "Parser.hpp"


class                   ParserLexer : public IParser
{
private:
  t_ast_node	*_current;
  std::string	_phrase;
  size_t	_line;

public:
  ParserLexer();
  ~ParserLexer();
  void                  feed(const std::string &);
  void                  parseTree(t_ast_node &);
  t_ast_node            *createTree();

private:
  t_ast_node            *createNode();
  void			parseLine(const std::string &);
  void			getForm(const std::string &);
  void			checkSection(const std::string &);
  void			checkComponent(const std::string &);
  void			checkAlphaNum(const std::string &);
  void			checkNum(const std::string &);
  void			createComponentNode(const std::string &);
  void			createLinkNode(const std::string &);
  t_ast_node		*createLinkSubNode(const std::string &);
  void			sortTree(t_ast_node &);
  std::string		getLine(std::string &);
  int			spaceCount(const std::string &);
  void		        cleanStr(std::string &);
  void			showTree(t_ast_node &);
};

#endif
