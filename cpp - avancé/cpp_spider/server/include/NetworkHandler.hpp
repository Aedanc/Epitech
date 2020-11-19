//
// NetworkHandler.hpp for Spider in /home/nicolas/Projects/C++/cpp_spider/server/src
// 
// Made by nicolas
// Login   <nicolas.giacomarosa@epitech.eu>
// 
// Started on  Thu Sep 28 14:41:15 2017 nicolas
// Last update Fri Oct  6 22:12:16 2017 nicolas
//

#ifndef		_NETWORKHANDLER_HPP_
# define	_NETWORKHANDLER_HPP_

#include	<boost/asio.hpp>
#include	<boost/bind.hpp>
#include	<boost/thread.hpp>
#include	<boost/asio/ssl.hpp>
#include	<unordered_map>
#include	"Client.hpp"

typedef boost::asio::ssl::stream<boost::asio::ip::tcp::socket> ssl_socket;

class		NetworkHandler
{
private:
  unsigned int					_it;
  std::unordered_map<unsigned int, Client *>	_client_list;
  boost::thread					*_thread;
  boost::asio::io_service			_ioservice;
  boost::asio::ip::tcp::acceptor		_acceptor;
  boost::asio::ip::tcp::acceptor		_acceptor2;
  boost::asio::ssl::context			_context;
  void						start_accept();
  void						handle_data_socket(Client *client, const boost::system::error_code& error);
  void						handle_accept(Client *client, const boost::system::error_code& error);
  void						stop_client_socket();
  std::string					get_password() const;
public:
  NetworkHandler();
  ~NetworkHandler();
  void						print_client_list();
  void						stop_server();
};

#endif		/*!_NETWORKHANDLER_HPP_*/
