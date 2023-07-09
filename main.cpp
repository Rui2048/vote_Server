#include "service.h"
#include <assert.h>

int main(int argc, char *argv[])
{
    Config config;
    config.parse_arg(argc, argv);
    VoteServer server;
    server.setPort(config.PORT);
    int ret;
    ret = server.init();
    assert(ret == 0);
    ret = server.startListen();
    //ret = server.connectToServer();
    assert(ret == 0);
    server.eventLoop();
    return 0;
}