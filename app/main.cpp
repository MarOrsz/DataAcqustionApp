#include <string>
#include <iostream>

#include "TcpServer.h"
#include "WebSocketClient.h"

int main()
{
    TcpServer server1;
    server1.serverListen();

    WebSocketClient webSocketClient("localhost", "8000");
    webSocketClient.sendAndReceive("Marcin");
    
    std::string command;

    while (command != "exit")
    {
        std::cin >> command;
    }

    return 0;
}