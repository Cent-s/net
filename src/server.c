#include <stdio.h>
#include "net.h"

int main(void) {
    char buffer[BUFSIZ];

    int listener = listen_net("127.0.0.1", 5555);
    int conn = accept_net(listener);

    recv_net(conn, buffer, BUFSIZ);
    printf("%s\n", buffer);

    close_net(conn);
    close_net(listener);

    return 0;
}
