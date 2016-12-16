#include "common.h"

KVS_TABLE *kvs_table;

int main() {

    ini_t *config = ini_load("../etc/kvs.ini");

    // get config
    const char *protocol = ini_get(config, "base", "protocol");
    const char *bind_ip_s = ini_get(config, "base", "ip");
    const char *port_s = ini_get(config, "base", "port");
    // const char *data_dir_s = ini_get(config, "base", "data_dir");
    const char *backlog_s = ini_get(config, "base", "backlog");

    int backlog = atoi(backlog_s);
    int port = atoi(port_s);
    int sockfd;

    // init memory
    K_TABLE_INIT(&kvs_table)

    // init network
    if (strcmp(protocol, K_P_TCP) == 0) {
        sockfd = knet_tcp_init(bind_ip_s, (uint32_t)port, backlog);
    } else if (strcmp(protocol, K_P_UNIX_DOMAIN) == 0) {
        printf("unix domain:%s\n", protocol);
    }

    return 0;
}
