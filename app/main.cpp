#include <string>



#include "TcpServer.h"

int main()
{
    TcpServer server1;
    server1.serverListen();

    std::string command;

    while (command != "exit")
    {}
    

    return 0;
}