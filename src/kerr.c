#include "common.h"
#include "kerr.h"

void kvs_err_record(char *error, uint8_t type)
{
}

void kvs_err_print(char *error, uint8_t type)
{

    switch (type)
    {
        case ERR_TYPE_ERROR:
            printf("KVS ERROR:%s\n", error);
            exit(1);
            break;
        case ERR_TYPE_WARNING:
            printf("KVS WARNING:%s\n", error);
            break;
        case ERR_TYPE_NOTICE:
            printf("KVS NOTICE:%s\n", error);
            break;
        default:
            printf("UNKNOWN:%s\n", error);
            break;
    }
}

void kvs_debug_info_s(char *info)
{
    printf("KVS DEBUG:%s\n", info);
}

void kvs_debug_info_d(double info)
{
    printf("KVS DEBUG:%f\n", info);
}
