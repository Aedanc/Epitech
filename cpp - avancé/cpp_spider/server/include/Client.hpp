//
// Client.hpp for spider in /home/nicolas/Projects/C++/cpp_spider/server/src
//
// Made by nicolas
// Login   <nicolas.giacomarosa@epitech.eu>
//
// Started on  Mon Oct  2 15:24:39 2017 nicolas
// Last update Mon Oct  9 23:24:15 2017 nicolas
//

#ifndef		_CLIENT_HPP_
# define	_CLIENT_HPP_

#define		MAX_LENGTH      10000

#include	<boost/asio.hpp>
#include	<boost/bind.hpp>
#include	<boost/asio/ssl.hpp>
#include	<unordered_map>
#include	<iostream>
#include	"Parser/Parser.h"
#include	"log.hpp"

typedef	boost::asio::ssl::stream<boost::asio::ip::tcp::socket>	ssl_socket;

class		Client
{
private:
  ssl_socket					_socket;
  ssl_socket					_data_socket;
    std::unordered_map<unsigned int, Client *>	*_client_list;
  Parser					_parser;
  char						_data[MAX_LENGTH];
  class log					_logger;
  char						*_data2;
  unsigned int					_id;
  void						handle_handshake(const boost::system::error_code& error);
  void						handle_data_handshake(const boost::system::error_code& error);
  void						handle_read(const boost::system::error_code &error, size_t bytes_transferred);
  void						handle_write(const boost::system::error_code &error);
  void						handle_data_read(const boost::system::error_code &error, size_t bytes_transferred);
  void						handle_data_write(const boost::system::error_code &error);
public:
  Client(boost::asio::io_service &io_service,
	 boost::asio::ssl::context &context,
	 std::unordered_map<unsigned int, Client *> *list);
  ~Client();
  ssl_socket::lowest_layer_type&		getDataSocket();
  ssl_socket::lowest_layer_type&		socket();
  void						setId(unsigned int);
  unsigned int					getId();
  void						start();
  void						start_data_socket();
};

#endif		/*!_CLIENT_HPP_*/
