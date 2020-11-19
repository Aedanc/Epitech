//
// NetworkHandler.cpp for Spider in /home/nicolas/Projects/C++/cpp_spider/server/src
// 
// Made by nicolas
// Login   <nicolas.giacomarosa@epitech.eu>
// 
// Started on  Thu Sep 28 15:01:11 2017 nicolas
// Last update Mon Oct  9 23:46:13 2017 nicolas
//

#include	"NetworkHandler.hpp"

NetworkHandler::NetworkHandler() : _acceptor(_ioservice, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), static_cast<int>(4242))),
				   _acceptor2(_ioservice, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), static_cast<int>(8484))),
				   _context(boost::asio::ssl::context::sslv23)
				   
{
  _context.set_options(boost::asio::ssl::context::default_workarounds
		       | boost::asio::ssl::context::no_sslv2
		       | boost::asio::ssl::context::single_dh_use);
  _context.set_password_callback(boost::bind(&NetworkHandler::get_password, this));
  _context.use_certificate_chain_file("openssl/server.crt");
  _context.use_private_key_file("openssl/server.key", boost::asio::ssl::context::pem);
  _context.use_tmp_dh_file("openssl/dh512.pem");
  start_accept();
  _thread = new boost::thread(boost::bind(&boost::asio::io_service::run, &_ioservice));
  _it = 0;
  std::cout << "Server ready and waiting for a connection" << std::endl;
}

NetworkHandler::~NetworkHandler()
{}

std::string	NetworkHandler::get_password() const
{
  return ("test");
}

void		NetworkHandler::stop_server()
{
  _thread->interrupt();
  _ioservice.stop();
  this->stop_client_socket();
}

void		NetworkHandler::stop_client_socket()
{
  std::unordered_map<unsigned int, Client *>::iterator it = _client_list.begin();

  while (it != _client_list.end())
    {
      it->second->socket().close();
      it->second->getDataSocket().close();
      it++;
    }
  _client_list.clear();
}

void		NetworkHandler::start_accept()
{
  Client	*client = new Client(_ioservice, _context, &_client_list);

  _acceptor.async_accept(client->socket(),
			 boost::bind(&NetworkHandler::handle_accept, this, client,
				     boost::asio::placeholders::error));
  _acceptor2.async_accept(client->getDataSocket(),
			  boost::bind(&NetworkHandler::handle_data_socket, this, client,
				      boost::asio::placeholders::error));
}

void		NetworkHandler::print_client_list()
{
  std::unordered_map<unsigned int, Client *>::iterator	it = _client_list.begin();

  if (it == _client_list.end())
    std::cout << "[SERVER] No client connected" << std::endl;
  while (it != _client_list.end())
    {
      std::cout << it->first << " connected" << std::endl;
      it++;
    }
}

void		NetworkHandler::handle_data_socket(Client *client,
						   const boost::system::error_code &error)
{
  std::cout << "New data socket" << std::endl;
  if (!error)
    {
      client->start_data_socket();
    }
  start_accept();
}

void		NetworkHandler::handle_accept(Client *client,
					      const boost::system::error_code &error)
{
  std::cout << "New client" << std::endl;
  if (!error)
    {
      _client_list.insert(std::make_pair(_it, client));
      client->setId(_it);
      _it++;
      client->start();
    }
  /*  else
      delete client;*/
  start_accept();
}
