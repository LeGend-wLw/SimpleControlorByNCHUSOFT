#ifndef NETWORK_H
#define NETWORK_H

#include <WinSock2.h>

#ifndef WAITING_TIME
#define WAITING_TIME 100
#endif

#ifndef SEPERATE
#define SEPERATE 50
#endif

class Network
{

  private:
    static Network *instance;
    Network();

  public:
    static Network &get_instance();
    ~Network();

    void sendPitch(INT16 val);
    void sendRoll(INT16 val);
    void sendTh(INT16 val);
    void sendYaw(INT16 val);
    void sendSw(bool val);
    Network operator=(const Network &) = delete;

  private:
    const char *IP = "192.168.8.1";

    WSAData wsadata;
    SOCKET pitchSock = INVALID_SOCKET;
    sockaddr_in pitchAddr;

    SOCKET rollSock = INVALID_SOCKET;
    sockaddr_in rollAddr;

    SOCKET ThSock = INVALID_SOCKET;
    sockaddr_in THAddr;

    SOCKET YawSock = INVALID_SOCKET;
    sockaddr_in YawAddr;

    SOCKET SwSock = INVALID_SOCKET;
    sockaddr_in SwAddr;
};

#endif // NETWORK_H
