#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

int connectTCP(const char *ip,u_short port)
{
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)

        return 1;

    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        std::cout << "Could not create socket : " << WSAGetLastError();
        return 1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port); //服务器端口
    server.sin_addr.s_addr = inet_addr(ip); //服务器IP

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        return 1;
    }
    return 0;
}
void disconnectTCP(void)
{
    closesocket(sock);
    WSACleanup();
}
