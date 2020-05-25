#include "TCPServer.h"

#define ASIO_STANDALONE
#include "asio.hpp"
#include <set>
#include <array>
#include <mutex>

class TCPServerImp : public TCPServer
{
public:
	friend class TCPConnection;
	class TCPConnection : public std::enable_shared_from_this<TCPConnection>
	{
	public:
		TCPConnection(TCPServerImp& server, asio::ip::tcp::socket socket)
			:_socket(std::move(socket)), _server(server)
		{
		}

		void start()
		{
			do_read();
		}

		void stop()
		{
			// Initiate graceful connection closure.
			asio::error_code ignored_ec;
			_socket.shutdown(asio::ip::tcp::socket::shutdown_both, ignored_ec);
			_socket.close();
		}

		void write(unsigned char* buffer, int length)
		{
			auto self(shared_from_this());
			std::shared_ptr<unsigned char> wbuf(new unsigned char[length]);
			std::copy(buffer, buffer + length, wbuf.get());
			asio::async_write(_socket, asio::buffer(wbuf.get(), length),
				[this, self, wbuf](asio::error_code ec, std::size_t)
			{
				if (ec && ec != asio::error::operation_aborted)
				{
					_server.do_stop_connection(shared_from_this());
				}
			});
		}

	private:
		void do_read()
		{
			auto self(shared_from_this());
			_socket.async_read_some(asio::buffer(_buffer),
				[this, self](asio::error_code ec, std::size_t bytes_transferred)
			{
				if (!ec)
				{
					_server._recv_fun(this, _buffer.data(), (int)bytes_transferred);

					do_read();
				}
				else if (ec != asio::error::operation_aborted)
				{
					_server.do_stop_connection(shared_from_this());
				}
			});
		}

		asio::ip::tcp::socket _socket;
		TCPServerImp& _server;
		std::array<unsigned char, 1024*64> _buffer;
	};
	typedef std::shared_ptr<TCPConnection> TCPConnectionPtr;

public:
	TCPServerImp(int port, TCPRecvDataFun fun)
		:_port(port),
		_io_context(1),
		_signals(_io_context),
		_acceptor(_io_context),
		_recv_fun(fun)
	{
	}

	virtual ~TCPServerImp()
	{
	}

	virtual void Run() override
	{
		_signals.add(SIGINT);
		_signals.add(SIGTERM);
#if defined(SIGQUIT)
		_signals.add(SIGQUIT);
#endif // defined(SIGQUIT)

		do_await_stop();

		asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), _port);
		_acceptor.open(endpoint.protocol());
		_acceptor.set_option(asio::ip::tcp::acceptor::reuse_address(true));
		_acceptor.bind(endpoint);
		_acceptor.listen();

		do_accept();

		_io_context.run();
	}

	virtual void Stop() override
	{
		_acceptor.close();
		do_stop_all_connection();
		_io_context.stop();
	}

	virtual bool Send(TCPConnectHandle handle, unsigned char* buffer, int length) override
	{
		std::lock_guard<std::recursive_mutex> lock(_mutex);
		for (auto connection : _connections)
		{
			if (connection.get() == handle)
			{
				connection->write(buffer, length);
				return true;
			}
		}

		return false;
	}

	virtual bool SendtoAll(unsigned char* buffer, int length) override
	{
		std::lock_guard<std::recursive_mutex> lock(_mutex);
		for (auto connection : _connections)
		{
			connection->write(buffer, length);
		}
		return true;
	}

private:
	void do_accept()
	{
		_acceptor.async_accept(
			[this](asio::error_code ec, asio::ip::tcp::socket socket)
		{
			if (!_acceptor.is_open())
			{
				return;
			}

			if (!ec)
			{
				do_add_connection(std::make_shared<TCPConnection>(*this, std::move(socket)));
			}

			do_accept();
		});
	}

	void do_await_stop()
	{
		_signals.async_wait(
			[this](std::error_code /*ec*/, int /*signo*/)
		{
			Stop();
		});
	}

	void do_add_connection(TCPConnectionPtr connection)
	{
		std::lock_guard<std::recursive_mutex> lock(_mutex);
		_connections.insert(connection);
		connection->start();
	}

	void do_stop_connection(TCPConnectionPtr connection)
	{
		std::lock_guard<std::recursive_mutex> lock(_mutex);
		_connections.erase(connection);
		connection->stop();
	}

	void do_stop_all_connection()
	{
		std::lock_guard<std::recursive_mutex> lock(_mutex);
		for (auto connection : _connections)
		{
			connection->stop();
		}
		_connections.clear();
	}

	int _port;
	asio::io_context _io_context;
	asio::signal_set _signals;
	asio::ip::tcp::acceptor _acceptor;
	TCPRecvDataFun _recv_fun;
	std::set<TCPConnectionPtr> _connections;
	std::recursive_mutex _mutex;
};

TCPServerPtr TCPServer::GetInstance(int port, TCPRecvDataFun fun)
{
	return std::make_shared<TCPServerImp>(port, fun);
}
