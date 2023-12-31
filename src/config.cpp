#include "config.h"

Config::Config(){
    //端口号,默认9000
    PORT = 9080;
}

void Config::parse_arg(int argc, char*argv[]){
    int opt;
    const char *str = "p:";
    while ((opt = getopt(argc, argv, str)) != -1)
    {
        switch (opt)
        {
        case 'p':
        {
            PORT = atoi(optarg);
            break;
        }
        default:
            break;
        }
    }
}