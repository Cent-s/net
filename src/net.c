#include <arpa/inet.h>
#include <unistd.h>

#include "net.h"

typedef enum error_t {
    SOCKET_ERR = -1,
    SETOPT_ERR = -2,
    BIND_ERR = -3,
    LISTEN_ERR = -4,
    CONNECT_ERR = -5,
} error_t;

int listen_net(char *ipv4, int port) {
    int listener = socket(AF_INET, SOCK_STREAM, 0);
    if (listener < 0) {
        return SOCKET_ERR;
    }
    if (setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0) {
        return SETOPT_ERR;
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ipv4);
    if (bind(listener, (struct sockaddr*)&addr, sizeof(addr)) != 0) {
        return BIND_ERR;
    }
    if (listen(listener, SOMAXCONN) != 0) {
        return LISTEN_ERR;
    }
    return listener;
}

int accept_net(int listener) {
    return accept(listener, NULL, NULL);
}

int connect_net(char *ipv4, int port) {
    int conn = socket(AF_INET, SOCK_STREAM, 0);
    if (conn < 0) {
        return SOCKET_ERR;
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ipv4);
    if (connect(conn, (struct sockaddr*)&addr, sizeof(addr)) != 0) {
        return CONNECT_ERR;
    }
    return conn;
}

int close_net(int conn) {
    return close(conn);
}

ssize_t send_net(int conn, char *buffer, size_t size) {
    return send(conn, buffer, size, 0);
}

ssize_t recv_net(int conn, char *buffer, size_t size) {
    return recv(conn, buffer, size, 0);
}
