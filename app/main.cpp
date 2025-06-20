#include <string>
#include <iostream>

#include "TcpServer.h"
#include "WebSocketClient.h"
#include "DataQueue.h"
#include "DataProcessor.h"




int main()
{
    DataQueue dataQueue;

    TcpServer server1(dataQueue);
    server1.serverListen();

    DataProcessor processor(dataQueue);
    processor.start();

    // WebSocketClient webSocketClient("localhost", "8000");
    // webSocketClient.sendAndReceive("Marcin");
    
    std::string command;

    while (command != "exit")
    {
        std::cin >> command;
    }

    return 0;
}