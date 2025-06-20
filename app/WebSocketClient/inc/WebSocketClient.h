#ifndef WEBSOCKET_CLIENT_HPP
#define WEBSOCKET_CLIENT_HPP

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <string>

namespace beast = boost::beast;
namespace http = beast::http;
namespace websocket = beast::websocket;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

class WebSocketClient 
{
    public:
        WebSocketClient(const std::string& host, const std::string& port);
        ~WebSocketClient() = default;

        int run();
        void sendAndReceive(const std::string& text);


    private:
        std::string host_;
        std::string port_;
        net::io_context ioc_;
        websocket::stream<tcp::socket> ws_;

        bool m_connectionToServer;

        void setupConnection(tcp::resolver& resolver);
};

#endif // WEBSOCKET_CLIENT_HPP