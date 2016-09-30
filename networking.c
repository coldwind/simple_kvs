#include "common.h"

int knet_tcp_init(const char *ip, uint32_t port, int backlog) {
    int sock_fd, bind_res, listen_res;

    struct sockaddr_in serv_addr;

    serv_addr.sin_family = AF_INET;

    if (K_IS_NULL(ip)) {
        serv_addr.sin_addr.s_addr = INADDR_ANY;
    } else {
        serv_addr.sin_addr.s_addr = inet_addr(ip);
    }

    serv_addr.sin_port = htons(port);

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        K_ERR_P("socket can't start", ERR_TYPE_ERROR);
    }

    if ((bind_res = bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) != 0) {
        K_ERR_P("bind failure", ERR_TYPE_ERROR);
    }

    if ((listen_res = listen(sock_fd, backlog)) != 0) {
        K_ERR_P("listen failure", ERR_TYPE_ERROR);
    }

    return sock_fd;
}

int kvs_tcp_accept(int sock_fd) {
    int cli_fd = accept(sock_fd, (struct sockaddr*)&cli_addr, sizeof(cli_addr));

    return cli_fd;
}

int iomodel() {
    epoll_create();
}
