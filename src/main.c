#include <stdio.h>
#include "sds.h"

/*-----------------------------------------------------------------------------
 * Program main()
 *----------------------------------------------------------------------------*/

int main(int argc, char **argv) {
    sds welcomeMsg = sdsnew("Welcome to C!");
    printf("%s\n", welcomeMsg);

    sdsfree(welcomeMsg);
    return 0;
}