#include "./voteserver/service.h"
#include <assert.h>

int main(int argc, char *argv[])
{
    Config config;
    config.parse_arg(argc, argv);
    CacheServer server;
    server.setPort(config.PORT);
    server.init();
    int ret;
    ret = server.startListen();
    //ret = server.connectToServer();
    assert(ret == 0);
    server.eventLoop();
}