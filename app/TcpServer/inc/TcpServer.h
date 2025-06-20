#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

#include <winsock2.h>
#include <WS2tcpip.h>
#include <vector>
#include <string>

#include "DataQueue.h"


class TcpServer
{
    public:
        TcpServer(DataQueue& queue) : TcpServer(DEFAULT_PORT, queue) {};
        TcpServer(std::string port, DataQueue& queue);
        ~TcpServer();

        void serverListen();

    private:
        std::string m_port;
        WSAData m_wsaData;
        SOCKET m_listenSocket;
        std::vector<SOCKET> m_clientSockets;
        struct addrinfo *m_addrInfoResult, m_hints;
        DataQueue *m_dataQueue;

        void init();
        void getAddrInfo();
        void createSocket();
        void bindSocket();
        void run(SOCKET newClientSocket);
        void listening();
        virtual void processReceivedData();

        //helper methods
        void displayClientDetails(const sockaddr_in& clientAddress);
    
};