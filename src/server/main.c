#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "sds.h"
#include "zmq.h"

static volatile sig_atomic_t force_cancel_loop = 0;

/*-----------------------------------------------------------------------------
 * Utility functions
 *----------------------------------------------------------------------------*/

static void cleanup_and_exit(int signum) {
    force_cancel_loop = 1;
}

/*-----------------------------------------------------------------------------
 * Program main()
 *----------------------------------------------------------------------------*/

int main(int argc, char **argv) {
    sds welcomeMsg = sdsnew("Launching server...");
    printf("%s\n\n", welcomeMsg);
    sdsfree(welcomeMsg);

    signal(SIGINT, cleanup_and_exit);

    //  Socket to talk to clients
    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_REP);
    int rc = zmq_bind (responder, "tcp://*:5555");

    while (1) {
        char buffer [16];
        zmq_recv(responder, buffer, 16, 0);
        printf("%s Is it me you're looking for?\n", buffer);
        sleep(1);
        zmq_send(responder, "world\0", 8, 0);

        if (force_cancel_loop) {
            exit(0);
        }
    }
}