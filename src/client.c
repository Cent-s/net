#include <stdio.h>
#include "net.h"

int main(void) {
    char buffer[BUFSIZ] = "hello! how are you?";

    int conn = connect_net("127.0.0.1", 5555);
    send_net(conn, buffer, BUFSIZ);

    close_net(conn);

    return 0;
}
