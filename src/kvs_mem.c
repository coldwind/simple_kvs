#include "common.h"

void *kvs_table_malloc(size_t size) {

    if (size <= 0) {
        return NULL;
    }

    return malloc(sizeof(KVS_TABLE));
}

void kvs_table_free(void *mp) {
    K_TABLE_FREE(mp)
}

void kvs_table_init(KVS_TABLE **kv_table) {
    *kv_table = (KVS_TABLE *)K_TABLE_MALLOC(DEFAULT_HASH_CONTAINER)
}

void kvs_table_set(char *name, void *value) {
    uint32_t index = kvs_get_index(name);
    kvs_table
}

void kvs_table_get(char *name) {
    uint32_t index = kvs_get_index(name);
}

void kvs_table_remove(char *name) {
    uint32_t index = kvs_get_index(name);
}

static uint32_t kvs_get_index(char *key) {
    uint32_t hash = 0;
    while (*key) {
        hash = hash * 33 + (int)*key;
        key++;
    }

    return hash;
}
