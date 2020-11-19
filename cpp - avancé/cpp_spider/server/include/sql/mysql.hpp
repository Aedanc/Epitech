//
// mysql.hpp for mysql in /home/guesti_a/Bureau/Tek3/cpp_spider
// 
// Made by Guestin Antoine
// Login   <guesti_a@epitech.net>
// 
// Started on  Wed Oct  4 19:38:50 2017 Guestin Antoine
// Last update Sat Oct  7 21:09:48 2017 Guestin Antoine
//

#ifndef	_MYSQL_HPP_
# define _MYSQL_HPP_

#include	<string>
#include	"mysql.h"

class	Mysql
{
public:
  Mysql();
  ~Mysql();
  int		MysqlOptions(enum mysql_option option, const std::string arg);
  MYSQL		*MysqlRealConnect(std::string db);
  MYSQL		*MysqlConnect();
  int		MysqlQuery(std::string query);
  unsigned int	MysqlAffectedRows();
  MYSQL_RES	*MysqlUseResult();
  MYSQL_ROW	MysqlFetchRow(MYSQL_RES *result);
  int		MysqlPing();
  unsigned int	MysqlNumFields(MYSQL_RES *result);
  unsigned long *MysqlFetchLengths(MYSQL_RES *result);
  void		MysqlFreeResult(MYSQL_RES *result);
private:
  MYSQL		mysql;
  unsigned int	port;
  std::string	host;
  std::string	user;
  std::string	passwd;
};

#endif		/* !_MYSQL_HPP_ */