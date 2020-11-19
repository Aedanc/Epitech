//
// Client.cpp for spider in /home/nicolas/Projects/C++/cpp_spider/server/src
//
// Made by nicolas
// Login   <nicolas.giacomarosa@epitech.eu>
//
// Started on  Mon Oct  2 15:24:12 2017 nicolas
// Last update Mon Oct  9 23:51:17 2017 nicolas
//

#include	"Client.hpp"

Client::Client(boost::asio::io_service &io_service,
	       boost::asio::ssl::context &context,
	       std::unordered_map<unsigned int, Client *> *list) : _socket(io_service, context),
								   _data_socket(io_service, context),
								   _client_list(list),
								   _parser(_id, _logger.vkCodesMap)

{
  if ((_data2 = (char *)malloc(sizeof(t_input) * 600 + 8)) == NULL)
    std::cerr << "Error with malloc" << std::endl;
  _id = 0;
}

Client::~Client()
{
  _client_list->erase(_id);
  std::cout << "Client deleted" << std::endl;
}

void		Client::start()
{
  _socket.async_handshake(boost::asio::ssl::stream_base::server,
			  boost::bind(&Client::handle_handshake, this,
				      boost::asio::placeholders::error));
}

void		Client::start_data_socket()
{
  _data_socket.async_handshake(boost::asio::ssl::stream_base::server,
			       boost::bind(&Client::handle_data_handshake, this,
					   boost::asio::placeholders::error));
}


void		Client::handle_handshake(const boost::system::error_code& error)
{
  if (!error)
    {
      boost::system::error_code			ignored_error;
      std::string				message = "8484";

      boost::asio::write(_socket, boost::asio::buffer(message),
			 boost::asio::transfer_all(), ignored_error);
      _socket.async_read_some(boost::asio::buffer(_data, MAX_LENGTH),
			      boost::bind(&Client::handle_read, this,
					  boost::asio::placeholders::error,
					  boost::asio::placeholders::bytes_transferred));
    }
  /*  else
      delete this;*/
}

void		Client::handle_data_handshake(const boost::system::error_code& error)
{
  if (!error)
    {
      _data_socket.async_read_some(boost::asio::buffer(_data2, MAX_LENGTH),
				   boost::bind(&Client::handle_data_read, this,
					       boost::asio::placeholders::error,
					       boost::asio::placeholders::bytes_transferred));
    }
}

void		Client::handle_data_write(const boost::system::error_code &error)
{
  if (!error)
    {}
}

void		Client::handle_data_read(const boost::system::error_code &error,
					 size_t bytes_transferred)
{
  std::stringstream cleanLog;

  (void)bytes_transferred;
  if (!error)
    {
      _parser.parsePacket(_data2);
      _data_socket.async_read_some(boost::asio::buffer(_data2, MAX_LENGTH),
				   boost::bind(&Client::handle_data_read, this,
					       boost::asio::placeholders::error,
					       boost::asio::placeholders::bytes_transferred));
      _logger.analyse_data(_parser.inputs, cleanLog);
      _logger.write_data(cleanLog, _id);
    }
  else
    delete this;
}

void		Client::handle_read(const boost::system::error_code& error,
				    size_t bytes_transferred)
{
  (void)bytes_transferred;
  if (!error)
    {
      std::cout << _data;
      _socket.async_read_some(boost::asio::buffer(_data, MAX_LENGTH),
			      boost::bind(&Client::handle_read, this,
					  boost::asio::placeholders::error,
					  boost::asio::placeholders::bytes_transferred));
    }
  /*  else
    {
      delete this;
      }*/
}

void		Client::handle_write(const boost::system::error_code& error)
{
  if (!error)
    {
      boost::asio::streambuf send_buffer;

      std::cout << "writing to socket" << std::endl;
      boost::asio::async_write(_socket, send_buffer,
			       boost::bind(&Client::handle_write, this,
					   boost::asio::placeholders::error));
    }
  /*  else
    {
      delete this;
      }*/
}

ssl_socket::lowest_layer_type&		Client::socket()
{
  return (_socket.lowest_layer());
}

ssl_socket::lowest_layer_type&		Client::getDataSocket()
{
  return (_data_socket.lowest_layer());
}

void					Client::setId(unsigned int id)
{
  _id = id;
}

unsigned int				Client::getId()
{
  return (_id);
}
