#include "WebSocketClient.h"
#include <iostream>

WebSocketClient::WebSocketClient(const std::string& host, const std::string& port)
    : host_(host), port_(port), ws_(ioc_), m_connectionToServer{false}
    {
        this->run();
    }

int WebSocketClient::run() 
{
    try {
        tcp::resolver resolver{ioc_};
        setupConnection(resolver);
        m_connectionToServer = true;
        return EXIT_SUCCESS;
    } catch (std::exception const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        m_connectionToServer = false;
        return EXIT_FAILURE;
    }
}

void WebSocketClient::setupConnection(tcp::resolver& resolver) 
{
    auto const results = resolver.resolve(host_, port_);
    auto ep = net::connect(ws_.next_layer(), results);
    host_ += ':' + std::to_string(ep.port());

    ws_.set_option(websocket::stream_base::decorator(
        [](websocket::request_type& req) {
            req.set(http::field::user_agent,
                    std::string(BOOST_BEAST_VERSION_STRING) + " websocket-client-coro");
        }));

    ws_.handshake(host_, "/ws");
}

void WebSocketClient::sendAndReceive(const std::string& text) 
{
    if(!m_connectionToServer)
        this->run();
    
    if(m_connectionToServer)
    {
        ws_.write(net::buffer(text));
        beast::flat_buffer buffer;
        ws_.read(buffer);
        //ws_.close(websocket::close_code::normal);
        std::cout << beast::make_printable(buffer.data()) << std::endl;
    }

}