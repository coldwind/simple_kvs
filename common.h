#ifndef K_COMMON
#define K_COMMON

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <strings.h>
#include <string.h>

#include "kvs_mem.h"
#include "ini.h"
#include "networking.h"
#include "kerr.h"

#define K_NULL NULL
#define null NULL
#define K_IS_NULL(x) (x==K_NULL)
#define EPOLL_CREATE_SIZE 256

/* memeroy */
#define K_MALLOC(size) kvs_malloc(size)
#define K_FREE(kpoint) kvs_free(kpoint)

/* error keyword */
#define K_ERR_P(msg,type) kvs_err_print(msg,type)
#define K_ERR_R(msg,type) kvs_err_record(msg,type)

#define ERR_TYPE_NOTICE 1
#define ERR_TYPE_WARNING 2
#define ERR_TYPE_ERROR 3

/* protocol */
#define K_P_TCP "tcp"
#define K_P_UNIX_DOMAIN "unix_domain"

#endif
