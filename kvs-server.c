#include <stdio.h>
#include "ini.h"
#include "networking.h"

int main() {

    ini_t *config = ini_load("etc/kvs.ini");

    // get config
    const char *bind_ip = ini_get(config, "base", "ip");
    const char *port = ini_get(config, "base", "port");
    const char *data_dir = ini_get(config, "base", "data_dir");

    // init network

    return 0;
}
