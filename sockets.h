#ifndef SOCKET_H
#define SOCKET_H
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <bits/stdc++.h>
#include "QDebug"
using namespace std;


class Socket
{
public:
    static Socket & getInstance(){
        static Socket instance;
        return instance;
    }
    Socket();
    void enviar(string mensaje, int puerto, string ip);
    string escuchaEnvia(int puerto, string mensaje);
    string envioEscucho(string mensaje, int puerto, string ip);
    static int turno;
    static bool play;
    static int vida;
};

#endif // SOCKET_H
