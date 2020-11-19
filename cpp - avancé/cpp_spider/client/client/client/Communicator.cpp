//
//	Created by sylvain.chaugny@epitech.eu on 04/10/17
//

#include "Communicator.h"
#include <iostream>
#include <boost/bind.hpp>
#include <boost/array.hpp>
#include "macros.h"

spider::client::Communicator::Communicator() :
	_io_service(),
	_resolver(_io_service),
	_ctx(boost::asio::ssl::context::sslv23)
{
	try
	{
		_ctx.load_verify_file(CERT_FILE);
	}
	catch (std::exception const &e)
	{
		OutputDebugString(e.what());
		OutputDebugString("\n");
	}
}

spider::client::Communicator::~Communicator()
{
	stop();
}

int				spider::client::Communicator::init(std::string const &addr, std::string const &port)
{
	try
	{
		_query = new boost::asio::ip::tcp::resolver::query(addr, port);
		_destination = _resolver.resolve(*_query);

		_socket = new ssl_socket(_io_service, _ctx);

		boost::asio::connect(_socket->lowest_layer(), _destination);
		_socket->lowest_layer().set_option(boost::asio::ip::tcp::no_delay(true));

		_socket->set_verify_mode(boost::asio::ssl::verify_peer);
		_socket->set_verify_callback(boost::bind(&spider::client::Communicator::verify_certificate, this, _1, _2));
		_socket->handshake(ssl_socket::client);
	}
	catch (std::exception const &e)
	{
		std::string error("SPIDER ERROR: <");
		error += std::string(e.what()) + ">\n";
		OutputDebugString(error.c_str());
		return 1;
	}
	return 0;
}

bool			spider::client::Communicator::verify_certificate(bool preverified, boost::asio::ssl::verify_context& ctx)
{
	char subject_name[256];
	X509* cert = X509_STORE_CTX_get_current_cert(ctx.native_handle());
	X509_NAME_oneline(X509_get_subject_name(cert), subject_name, 256);
	std::cout << "Verifying " << subject_name << "\n";
	return preverified;
}

int				spider::client::Communicator::stop()
{
	delete _socket;
	delete _query;
	return 0;
}

size_t			spider::client::Communicator::send(char const *data, size_t const to_send)
{
	return _socket->write_some(boost::asio::buffer(data, to_send));
}

size_t			spider::client::Communicator::receive(std::string &data, size_t const to_read)
{
	std::vector<char>			read_data;
	boost::array<char, 1024>	buffer;
	size_t						read_bytes;
	size_t						total;

	total = 0;
	read_bytes = _socket->read_some(boost::asio::buffer(buffer));
	while (read_bytes && total <= to_read)
	{
		buffer[read_bytes] = 0;
		for (int i = 0; buffer[i]; i++)
			read_data.push_back(buffer[i]);
		read_data.push_back(0);
		buffer[0] = 0;
		total += read_bytes;
	}
	data = std::string(read_data.data());
	return data.size();
}