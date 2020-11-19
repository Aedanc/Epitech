//
// ParserLexer.cpp for nanotekspice in /home/quersi_l/rendu/WIP/nanotekspice
// 
// Made by Laurent QUERSIN
// Login   <quersi_l@epitech.net>
// 
// Started on  Wed Feb 15 09:04:35 2017 Laurent QUERSIN
// Last update Sat Mar  4 00:50:03 2017 Laurent QUERSIN
//

#include	"ParserLexer.hpp"
#include	"NanoTek.hpp"
#include	"Error.hh"

static const std::string  _sections[2]
{
  ".chipsets:",
    ".links"
};

static const std::string  _components[11]
{
  "input", 
    "output",
    "clock",
    "4001",
    "4008",
    "4011",
    "4030",
    "4040",
    "4069",
    "4071",
    "4081"
};

ParserLexer::ParserLexer()
{
  _current = NULL;
  _phrase = "";
  _line = 0;
}

ParserLexer::~ParserLexer()
{
}

void			ParserLexer::feed(const std::string &str)
{ 
  std::string sub = str;

  cleanStr(sub);
  _phrase += "\n";
  _phrase += sub;
}

t_ast_node		*ParserLexer::createTree()
{
  t_ast_node	*root;

  root = createNode();
  _current = root;
  _line = 0;

  while (_phrase.size() > 0)
    {
      std::string sub = getLine(_phrase);
      parseLine(sub);
    }
  _current = NULL;
  sortTree(*root);
  return (root);
}

void                    ParserLexer::parseLine(const std::string &str)
{
  _line++;
  if (str.length() == 0)
    return;
  getForm(str);
}

void			ParserLexer::getForm(const std::string &str)
{
  std::ostringstream oss;

  if (str == "")
    return;
  if (str[0] == '.')
    {
      checkSection(str);
      return;
    }
  if (spaceCount(str) == 1)
    {
      size_t pos = str.find(" ");
      std::string left = str.substr(0, pos);
      std::string right = str.substr(pos + 1);  

      if (left.find(":") != std::string::npos && right.find(":") != std::string::npos)
	{
	  createLinkNode(str);
	  return;
	}
      if (left.find(":") == std::string::npos && right.find(":") == std::string::npos)
	{
	  createComponentNode(str);
	  return;
	}
      if ((left.find(":") != std::string::npos && right.find(":") == std::string::npos) || (left.find(":") == std::string::npos && right.find(":") != std::string::npos))
	{
	  oss << "Unreconized form at line " << _line << ".";
	  throw ParsingError(oss.str());
	}
    }
  oss << "Unreconized form at line " << _line << ".";
  throw ParsingError(oss.str());
}

void		ParserLexer::checkSection(const std::string &str)
{
  std::ostringstream oss;
  size_t	count = 0;
  bool		found = false;

  while (count < 11 && found == false)
    {
      if (str.find(_sections[count++]) != std::string::npos)
	found = true;
    }
  if (found == false)
    {
      oss << "Section Error: Invalid section type at line " << _line << ".";
      throw ParsingError(oss.str());
    }
}

void			ParserLexer::checkComponent(const std::string &str)
{
  std::ostringstream oss;
  size_t	count = 0;
  bool		found = false;
  

  while (count < 11 && found == false)
    {
      if (str.find(_components[count++]) != std::string::npos)
	found = true;
    }
  if (found == false)
    {
      oss << "Component Error: Unknown component at line " << _line << '.';
      throw ParsingError(oss.str());
    }
}

void			ParserLexer::checkAlphaNum(const std::string &str)
{
  std::ostringstream oss;
  std::string::size_type i = 0;

  while (i < str.length() && (std::isalnum(str[i]) || str[i] == ' '))
    i++;
  if (i != str.length())
    {
      oss << "Component Error: name contains unvalid characters at line " << _line << ".";
      throw ParsingError(oss.str());
    }
}

void			ParserLexer::checkNum(const std::string &str)
{
  std::ostringstream oss;
  std::string::size_type i = 0;

   while (i < str.length() && std::isdigit(str[i]))
     i++;
   if (i != str.length())
     {
       oss << "LinkError: pin reference is not a number at line " << _line << ".";
       throw ParsingError(oss.str());
     }
   if (str == "")
     {
       oss << "Link Error: missing pin reference at line " << _line << '.';
       throw ParsingError(oss.str());
    }
}

t_ast_node*		ParserLexer::createNode()
{
  t_ast_node	*newNode;

  newNode = new t_ast_node(NULL);
  newNode->lexeme = "";
  newNode->type = ASTNodeType::DEFAULT;
  newNode->value = "";
  newNode->children = new std::vector<t_ast_node *>(2);
  (*newNode->children)[0] = NULL;
  (*newNode->children)[1] = NULL;
  return (newNode);
}

void		ParserLexer::createComponentNode(const std::string &str)
{
  size_t pos = str.find(" ");
  t_ast_node *nc = createNode();
  
  checkComponent(str);
  checkAlphaNum(str);
  nc->type = ASTNodeType::COMPONENT;
  nc->lexeme = str.substr(0, pos);
  nc->value = str.substr(pos + 1);
  (*_current->children)[0] = nc;
  _current = nc;
}

t_ast_node*	ParserLexer::createLinkSubNode(const std::string &str)
{
  std::ostringstream	oss;
  t_ast_node	*node;
  size_t	pos;
  std::string   lex;
  std::string   val;

  pos = str.find(":");
  lex = str.substr(0, pos);
  val = str.substr(pos + 1);
  checkNum(val);
  node = createNode();
  node->lexeme = lex;
  node->value = val;
  return (node);
}

void		ParserLexer::createLinkNode(const std::string &str)
{
  std::ostringstream	oss;
  size_t	pos;
  std::string	from;
  std::string   to;
  t_ast_node	*nf;
  t_ast_node	*nt;

  pos = str.find(" ");
  from = str.substr(0, pos);
  to = str.substr(pos + 1);

  nf = createLinkSubNode(from);
  nf->type = ASTNodeType::LINK;
  nt = createLinkSubNode(to);
  nt->type = ASTNodeType::LINK_END;

  (*nf->children)[1] = nt;
  (*_current->children)[0] = nf;
  _current = nf;
}

void			ParserLexer::parseTree(t_ast_node &tree)
{
  Circuit circuit;
  
  if (tree.type == ASTNodeType::COMPONENT)
    circuit.addComponent(tree.lexeme, tree.value);
  else if (tree.type == ASTNodeType::LINK && (*tree.children)[1] != NULL && (*tree.children)[1]->type == ASTNodeType::LINK_END)
    {
      std::istringstream s1(tree.value);
      std::istringstream s2((*tree.children)[1]->value);
      size_t		lpin;
      size_t		fpin;

      s1 >> lpin;
      s2 >> fpin;
      circuit.setLink(tree.lexeme, lpin, (*tree.children)[1]->lexeme, fpin);
    }
  if ((*tree.children)[0] != NULL)
    parseTree(*(*tree.children)[0]);
  if ((*tree.children)[1] != NULL)
    parseTree(*(*tree.children)[1]);
}

void			ParserLexer::sortTree(t_ast_node &tree)
{
  t_ast_node *current;
  t_ast_node *previous = NULL;
  t_ast_node *last = NULL;

  current = (*tree.children)[0];
  while (current != NULL)
    {
      if (previous != NULL)
	{
	  if (current->type == ASTNodeType::COMPONENT && (*current->children)[0] != NULL && (*current->children)[0]->type == ASTNodeType::LINK)
	    last = current;
	  else if (current->type == ASTNodeType::COMPONENT && previous->type == ASTNodeType::LINK)
	    {
	      (*previous->children)[0] = (*current->children)[0];
	      if (last == NULL)
		{
		  (*current->children)[0] = (*tree.children)[0];
		  (*tree.children)[0] = current;
		}
	      else
		{
		  (*current->children)[0] = (*last->children)[0];
		  (*last->children)[0] = current;
		}
	    }
	}
      previous = current;
      current = (*current->children)[0];
    }
}

  //CLEANING AND GETTERS FOR SUBSTREAMS

std::string		ParserLexer::getLine
(std::string &str)
{
  std::string	sub;
  size_t		j;
  
  j = str.find("\n");
  if (j == std::string::npos)
    j = str.length();
  sub = str.substr(0, j);
  str = str.replace(0, j + 1, "");
  return (sub);
}

int			ParserLexer::spaceCount(const std::string &str)
{
  int		count = 0;

  for(size_t i = 0; i < str.length(); ++i)
    {
      if (str[i] == ' ')
	count++;
    }
  return (count);
}

void			ParserLexer::cleanStr(std::string &str)
{
  size_t	i;
  bool		flip = false;

  while ((i = str.find("\t")) != std::string::npos)
    str.replace(i, 1, " ");
  if ((i = str.find_first_not_of(" ")) != std::string::npos)
    str.replace(0, i, "");
  if ((i = str.find_last_not_of(" ")) != std::string::npos)
    str.replace(i + 1, str.length() - i, "");
  while ((i = str.find("  ")) != std::string::npos)
    str.replace(i, 1, "");
  if ((i = str.find("#")) != std::string::npos)
    str.replace(i, str.length() - i, "");
  for (int j = 0; j < 2; ++j)
    {
      while ((i = str.find(_sections[j] + " ")) != std::string::npos)
	str.replace(i + _sections[j].length(), 1, "\n");
    }
  while ((i = str.find(" :")) != std::string::npos)
    str.replace(i, 1 ,"");
  while ((i = str.find(": ")) != std::string::npos)
    str.replace(i + 1, 1 ,"");
  i = 0;
  while ((i = str.find(" ", i + 1)) != std::string::npos)
    {
      if (flip == false)
	flip = true;
      else
	{
	  str.replace(i, 1, "\n");
	  flip = false;
	}
    } 
  if (str == " ")
    str = "";
}

  //DEBUG

void			ParserLexer::showTree(t_ast_node &node)
{
  std::cout << (int)node.type << " || " << node.lexeme << " -> " << node.value << std::endl;

  if ((*node.children)[1] != NULL)
    showTree(*(*node.children)[1]);
  if ((*node.children)[0] != NULL)
    showTree(*(*node.children)[0]);
}
