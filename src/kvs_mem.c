#include "common.h"

void *kvs_table_malloc(size_t size) {

    if (size <= 0) {
        return NULL;
    }

    return malloc(size);
}

void kvs_table_free(void *mp) {
    K_TABLE_FREE(mp)
}

void kvs_table_init(KVS_TABLE **kv_table) {
    *kv_table = (KVS_TABLE *)K_TABLE_MALLOC(DEFAULT_HASH_CONTAINER)
}

void kvs_table_set(char *name, void *value) {
}

void kvs_table_get(char *name) {
}

void kvs_table_remove(char *name) {
}
