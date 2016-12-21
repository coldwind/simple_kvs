#include "common.h"

void *kvs_table_malloc() {

    return malloc(sizeof(KVS_TABLE));
}

void kvs_table_free(void *mp) {
    K_TABLE_FREE(mp)
}

void kvs_table_init(KVS_TABLE **kv_table) {
    *kv_table = (KVS_TABLE *)K_TABLE_MALLOC()
    (*kv_table)->count = 0;
    (*kv_table)->vector_size = DEFAULT_HASH_CONTAINER;
}

void kvs_table_set(char *name, void *value) {
    uint32_t index = kvs_get_index(name);
}

void *kvs_table_get(char *name) {
    uint32_t index = kvs_get_index(name);

    if (index >= container_size) {
        return 0;
    }
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

    hash %= container_size;

    return hash;
}
