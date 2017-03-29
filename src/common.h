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
#include "kerr.h"

#define K_NULL NULL
#define null NULL
#define K_IS_NULL(x) (x==K_NULL)
#define EPOLL_CREATE_SIZE 256
#define KEY_LEN 16

/* debug flag */
#define DEBUG 1

#if DEBUG == 1
#define DEBUG_PRINT_S(info) kvs_debug_info_s(info)
#define DEBUG_PRINT_D(info) kvs_debug_info_d(info)
#else
#define DEBUG_PRINT_S(info)
#define DEBUG_PRINT_D(info)
#endif

/* memeroy */
#define K_TABLE_INIT(table) kvs_table_init(table)
#define K_TABLE_MALLOC() kvs_table_malloc()
#define K_TABLE_FREE(kpoint) kvs_table_free(kpoint)
#define DEFAULT_HASH_CONTAINER 16

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
