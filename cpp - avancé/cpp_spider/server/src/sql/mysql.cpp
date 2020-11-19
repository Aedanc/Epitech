//
// mysql.cpp for mysql in /home/guesti_a/Bureau/Tek3/cpp_spider
// 
// Made by Guestin Antoine
// Login   <guesti_a@epitech.net>
// 
// Started on  Wed Oct  4 19:38:41 2017 Guestin Antoine
// Last update Tue Oct 10 00:01:58 2017 nicolas
//

#include	<iostream>
#include	"sql/mysql.h"
#include	"sql/mysql.hpp"

Mysql::Mysql() : port(0), host("127.0.0.1"), user("root"), passwd("root")
{
  mysql_init(&this->mysql);
}

Mysql::~Mysql()
{
  mysql_close(&this->mysql);
}

int		Mysql::MysqlOptions(enum mysql_option option, std::string arg)
{
  int	err;

  if ((err = mysql_options(&this->mysql, option, arg.c_str())) != 0)
    std::cout << "[SQL] Bad option" << std::endl;
  return (err);
}

MYSQL		*Mysql::MysqlRealConnect(std::string db)
{
  return (mysql_real_connect(&this->mysql, this->host.c_str(), this->user.c_str(), this->passwd.c_str(), db.c_str(), this->port, NULL, 0));
}

MYSQL		*Mysql::MysqlConnect()
{
  return (mysql_real_connect(&this->mysql, this->host.c_str(), this->user.c_str(), this->passwd.c_str(), NULL, this->port, NULL, 0));
}

int		Mysql::MysqlQuery(std::string query)
{
  return ((mysql_query(&this->mysql, query.c_str())));
}

unsigned int	Mysql::MysqlAffectedRows()
{
  return (mysql_affected_rows(&this->mysql));
}

MYSQL_RES	*Mysql::MysqlUseResult()
{
  return (mysql_use_result(&this->mysql));
}

MYSQL_ROW	Mysql::MysqlFetchRow(MYSQL_RES *result)
{
  return (mysql_fetch_row(result));
}

void		MysqlFreeResult(MYSQL_RES *result)
{
  mysql_free_result(result);
}

int		Mysql::MysqlPing()
{
  return (mysql_ping(&this->mysql));
}

unsigned long	*Mysql::MysqlFetchLengths(MYSQL_RES *result)
{
  return (mysql_fetch_lengths(result));
}

unsigned int	Mysql::MysqlNumFields(MYSQL_RES *result)
{
  return (mysql_num_fields(result));
}

void		Mysql::MysqlFreeResult(MYSQL_RES *result)
{
  mysql_free_result(result);
}
