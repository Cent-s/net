#ifndef HTTP_SERVER_NET_H
#define HTTP_SERVER_NET_H

#include <stddef.h>

extern int listen_net(char *ipv4, int port);
extern int accept_net(int listener);

extern int connect_net(char *ipv4, int port);
extern int close_net(int conn);

extern ssize_t send_net(int conn, char *buffer, size_t size);
extern ssize_t recv_net(int conn, char *buffer, size_t size);

#endif //HTTP_SERVER_NET_H
