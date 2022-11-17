#include "network.h"

#include <iostream>

#pragma comment(lib, "Ws2_32.lib")

constexpr UINT16 rollPort = 2120;
constexpr UINT16 pitchPort = 1920;
constexpr UINT16 thPort = 1524;
constexpr UINT16 yawPort = 908;
constexpr UINT16 SwPort = 909;

Network *Network::instance = nullptr;

Network::Network()
{
#if _DEBUG
    std::cout << "Created!\n";
    int iResult;
    iResult =
#endif
        WSAStartup(MAKEWORD(2, 2), &wsadata);
#if _DEBUG
    if (iResult != NO_ERROR)
    {
        std::cout << "WSAStartup failed with error: " << iResult << "\n";
        exit(8);
    }
#endif
    pitchSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
#if _DEBUG
    if (pitchSock == INVALID_SOCKET)
    {
        std::cout << "socket failed with error: %" << WSAGetLastError() << "\n";
        WSACleanup();
        exit(9);
    }
#endif
    rollSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
#if _DEBUG
    if (rollSock == INVALID_SOCKET)
    {
        std::cout << "socket failed with error: %" << WSAGetLastError() << "\n";
        WSACleanup();
        exit(9);
    }
#endif
    ThSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
#if _DEBUG
    if (ThSock == INVALID_SOCKET)
    {
        std::cout << "socket failed with error: %" << WSAGetLastError() << "\n";
        WSACleanup();
        exit(9);
    }
#endif
    YawSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
#if _DEBUG
    if (YawSock == INVALID_SOCKET)
    {
        std::cout << "socket failed with error: %" << WSAGetLastError() << "\n";
        WSACleanup();
        exit(9);
    }
#endif

    SwSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
#if _DEBUG
    if (SwSock == INVALID_SOCKET)
    {
        std::cout << "socket failed with error: %" << WSAGetLastError() << "\n";
        WSACleanup();
        exit(9);
    }
#endif
    pitchAddr.sin_family = AF_INET;
    pitchAddr.sin_port = htons(pitchPort);
    pitchAddr.sin_addr.s_addr = inet_addr(IP);

    rollAddr.sin_family = AF_INET;
    rollAddr.sin_port = htons(rollPort);
    rollAddr.sin_addr.s_addr = inet_addr(IP);

    THAddr.sin_family = AF_INET;
    THAddr.sin_port = htons(thPort);
    THAddr.sin_addr.s_addr = inet_addr(IP);

    YawAddr.sin_family = AF_INET;
    YawAddr.sin_port = htons(yawPort);
    YawAddr.sin_addr.s_addr = inet_addr(IP);

    SwAddr.sin_family = AF_INET;
    SwAddr.sin_port = htons(SwPort);
    SwAddr.sin_addr.s_addr = inet_addr(IP);
}

Network::~Network()
{
#if _DEBUG
    std::cout << "Erased!\n";
#endif
    WSACleanup();
}

void Network::sendPitch(INT16 val)
{
#if _DEBUG
    int iResult;
    std::cout << "Sending a datagram to the receiver..." << pitchPort << "  data:" << val << std::endl;
    iResult =
#endif
        sendto(pitchSock, reinterpret_cast<const char *>(&val), sizeof(val), 0, (SOCKADDR *)&pitchAddr,
               sizeof(pitchAddr));
#if _DEBUG
    if (iResult == SOCKET_ERROR)
    {
        std::cout << "sendto failed with error:" << WSAGetLastError() << std::endl;
        closesocket(pitchSock);
        WSACleanup();
        exit(10);
    }
#endif
}

void Network::sendRoll(INT16 val)
{
#if _DEBUG
    int iResult;
    std::cout << "Sending a datagram to the receiver..." << rollPort << "  data:" << val << std::endl;
    iResult =
#endif
        sendto(rollSock, reinterpret_cast<const char *>(&val), sizeof(val), 0, (SOCKADDR *)&rollAddr, sizeof(rollAddr));
#if _DEBUG
    if (iResult == SOCKET_ERROR)
    {
        std::cout << "sendto failed with error: " << WSAGetLastError() << "\n";
        closesocket(rollSock);
        WSACleanup();
        exit(10);
    }
#endif
}

void Network::sendTh(INT16 val)
{
#if _DEBUG
    int iResult;
    std::cout << "Sending a datagram to the receiver..." << thPort << "  data:" << val << std::endl;
    iResult =
#endif
        sendto(ThSock, reinterpret_cast<const char *>(&val), sizeof(val), 0, (SOCKADDR *)&THAddr, sizeof(THAddr));
#if _DEBUG
    if (iResult == SOCKET_ERROR)
    {
        std::cout << "sendto failed with error: " << WSAGetLastError() << std::endl;
        closesocket(ThSock);
        WSACleanup();
        exit(10);
    }
#endif
}

void Network::sendYaw(INT16 val)
{
#if _DEBUG
    int iResult;
    std::cout << "Sending a datagram to the receiver..." << yawPort << "  data:" << val << std::endl;
    iResult =
#endif
        sendto(YawSock, reinterpret_cast<const char *>(&val), sizeof(val), 0, (SOCKADDR *)&YawAddr, sizeof(YawAddr));
#if _DEBUG
    if (iResult == SOCKET_ERROR)
    {
        printf("sendto failed with error: %d\n", WSAGetLastError());
        closesocket(YawSock);
        WSACleanup();
        exit(10);
    }
#endif
}

void Network::sendSw(bool val)
{
#if _DEBUG
    int iResult;
    std::cout << "Sending a datagram to the receiver..." << SwPort << "  data:" << val << std::endl;
    iResult =
#endif
        sendto(SwSock, reinterpret_cast<const char *>(&val), sizeof(val), 0, (SOCKADDR *)&SwAddr, sizeof(SwAddr));
#if _DEBUG
    if (iResult == SOCKET_ERROR)
    {
        printf("sendto failed with error: %d\n", WSAGetLastError());
        closesocket(SwSock);
        WSACleanup();
        exit(10);
    }
#endif
}

Network &Network::get_instance()
{
    if (Network::instance == nullptr)
        Network::instance = new Network();
    return *Network::instance;
}