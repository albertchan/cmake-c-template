#include <string.h>
#include <stdio.h>

#include <zmq.h>

int main(int argc, char **argv) {
    printf ("Connecting to server...\n");
    printf ("\n");

    void *context = zmq_ctx_new ();
    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://localhost:5555");

    int request_num;
    for (request_num = 0; request_num != 10; request_num++) {
        char buffer [16];
        printf("Hello! %d\n", request_num);
        zmq_send(requester, "Hello!\0", 8, 0);
        zmq_recv(requester, buffer, 16, 0);
        printf("Received: %s (%d)\n", buffer, request_num);
    }

    zmq_close(requester);
    zmq_ctx_destroy(context);

    return 0;
}