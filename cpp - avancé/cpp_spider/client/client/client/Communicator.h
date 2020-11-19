//
//	Created by sylvain.chaugny@epitech.eu on 04/10/17
//

#ifndef CPP_SPIDER_COMMUNICATOR_HPP
# define CPP_SPIDER_COMMUNICATOR_HPP

# include <string>
# include <boost/asio.hpp>
# include <boost/asio/ssl.hpp>

namespace spider
{
	typedef boost::asio::ssl::stream<boost::asio::ip::tcp::socket> ssl_socket;

	namespace client
	{
		class Communicator
		{
		private:
			boost::asio::io_service						_io_service;
			boost::asio::ip::tcp::resolver::query		*_query;
			boost::asio::ip::tcp::resolver				_resolver;
			boost::asio::ip::tcp::resolver::iterator	_destination;
			boost::asio::ip::tcp::resolver::iterator	_end;
			boost::asio::ip::tcp::endpoint				_endpoint;
			boost::asio::ssl::context					_ctx;
			ssl_socket									*_socket;

		public:
			Communicator();
			virtual ~Communicator();

			int init(std::string const &addr, std::string const &port);
			int stop();

			bool verify_certificate(bool preverified, boost::asio::ssl::verify_context& ctx);


			size_t send(char const *msg, size_t const to_send);
			size_t receive(std::string &data, size_t const to_read);
		};
	};
};

#endif // !CPP_SPIDER_COMMUNICATOR_HPP	