struct sockaddr_in cli_addr;

int knet_tcp_init(const char*, uint32_t, int);
int epoll_run(int);
void read_data(int fd);
