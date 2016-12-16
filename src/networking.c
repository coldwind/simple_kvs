#include "common.h"

int knet_tcp_init(const char *ip, uint32_t port, int backlog) {
    int sock_fd, bind_res, listen_res;

    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));

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

int epoll_run(int sock_fd) {

    int epoll_fd, nfds, connfd, i;
    struct sockaddr_in cli_addr;
    struct epoll_event ep_event, ep_events[EPOLL_CREATE_SIZE];
    socklen_t socklen = sizeof(cli_addr);

    ep_event.events = EPOLLIN | EPOLLET;
    ep_event.data.fd = sock_fd;

    epoll_fd = epoll_create(EPOLL_CREATE_SIZE);
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, sock_fd, &ep_event);

    for (;;) {
        nfds = epoll_wait(epoll_fd, ep_events, EPOLL_CREATE_SIZE, -1);
        for (i = 0; i < nfds; i++) {
            if (ep_events[i].data.fd == sock_fd) {
                ep_event.events = EPOLLIN | EPOLLET;
                ep_event.data.fd = connfd;
                connfd = accept(sock_fd, (struct sockaddr *)&cli_addr, &socklen);
                epoll_ctl(epoll_fd, EPOLL_CTL_ADD, connfd, &ep_event);
            } else if (ep_events[i].events & EPOLLIN) {
                // 读数据
            }
        }
    }

    return epoll_fd;
}


