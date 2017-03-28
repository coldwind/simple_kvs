#include "common.h"

KVS_TABLE *kvs_table;
uint32_t container_size = DEFAULT_HASH_CONTAINER;

int main() {
    K_TABLE_INIT(&kvs_table)
    printf("%d,%d\n", kvs_table->count, kvs_table->vector_size);

    return 0;
}
