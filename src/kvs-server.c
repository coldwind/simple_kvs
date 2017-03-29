#include "common.h"

#include "ini.h"
#include "kvs_mem.h"
#include "networking.h"

KVS_TABLE *kvs_table;
uint32_t container_size = DEFAULT_HASH_CONTAINER;

int main()
{

    ini_t *config = ini_load("../etc/kvs.ini");

    // get config
    const char *protocol = ini_get(config, "base", "protocol");
    const char *bind_ip_s = ini_get(config, "base", "ip");
    const char *port_s = ini_get(config, "base", "port");
    // const char *data_dir_s = ini_get(config, "base", "data_dir");
    const char *backlog_s = ini_get(config, "base", "backlog");

    DEBUG_PRINT_S("load ini file done");

    int backlog = atoi(backlog_s);
    int port = atoi(port_s);
    int sockfd;

    // init memory
    K_TABLE_INIT(&kvs_table);
    kvs_table_set("machao", "mamama");

    // init network
    if (strcmp(protocol, K_P_TCP) == 0)
    {
        DEBUG_PRINT_S("network protocol tcp");
        //sockfd = knet_tcp_init(bind_ip_s, (uint32_t)port, backlog);
    }
    else if (strcmp(protocol, K_P_UNIX_DOMAIN) == 0)
    {
        DEBUG_PRINT_S("network protocol unix domain");
    }

    return 0;
}
