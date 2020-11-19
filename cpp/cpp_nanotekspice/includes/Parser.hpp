//
// Parser.hpp for nanotekspice in /home/quersi_l/rendu/WIP/nanotekspice
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Wed Feb 15 09:01:45 2017 Laurent QUERSIN
// Last update Wed Feb 15 09:02:25 2017 Laurent QUERSIN
//


#ifndef PARSER_HPP_
# define PARSER_HPP_

#include	<sstream>
#include	<string>
#include	<vector>

enum class		ASTNodeType : int
{ 
  DEFAULT = -1,
    NEWLINE = 0,
    SECTION,
    COMPONENT,
    LINK,
    LINK_END,
    STRING
};

typedef struct		s_ast_node
{
  s_ast_node(std::vector<struct s_ast_node *> *children) : children(children) {}
  std::string				lexeme;
  ASTNodeType				type;
  std::string				value;
  std::vector<struct s_ast_node *>	*children;
}			t_ast_node;

class			IParser
{
public:
  virtual ~IParser() {}
  virtual void		feed(const std::string &) = 0;
  virtual void		parseTree(t_ast_node &) = 0;
  virtual t_ast_node	*createTree() = 0;
};

#endif
