#include "common.h"
#include "kvs_mem.h"

void *kvs_table_malloc()
{
    return malloc(sizeof(KVS_TABLE));
}

kvs_mem_data *kvs_node_malloc()
{
    return (kvs_mem_data *)malloc(sizeof(kvs_mem_data));
}

void kvs_table_free(void *mp)
{
    K_TABLE_FREE(mp);
}

void kvs_table_init(KVS_TABLE **kv_table)
{
    DEBUG_PRINT_S("mem init");
    *kv_table = (KVS_TABLE *)K_TABLE_MALLOC();
    (*kv_table)->count = 0;
    (*kv_table)->vector_size = DEFAULT_HASH_CONTAINER;

    for (int i = 0; i < DEFAULT_HASH_CONTAINER; i++)
    {
        *kv_table->data[i] = kvs_node_malloc();
        *kv_table->data[i]->key = K_NULL;
        *kv_table->data[i]->val = K_NULL;
        *kv_table->data[i]->next = K_NULL;
    }
    DEBUG_PRINT_S("mem init");
    DEBUG_PRINT_D((*kv_table)->vector_size);
}

void kvs_table_set(char *name, void *value)
{
    uint32_t index = kvs_get_index(name);

    // check table
    kvs_mem_data *temp_data;
    do {
        temp_data = kvs_table->data[index];
        if (temp_data->key == K_NULL)
        {
            kvs_table->data[index] = kvs_node_malloc();
            kvs_table->data[index]->next = temp_data;

            strcpy(kvs_table->data[index]->key, name);
            strcpy(kvs_table->data[index]->val, (char *)value);
            break;
        }
    }
    while (1);
}

void *kvs_table_get(char *name)
{
    uint32_t index = kvs_get_index(name);

    if (index >= container_size)
    {
        return 0;
    }
}

void kvs_table_remove(char *name)
{
    uint32_t index = kvs_get_index(name);
}

static uint32_t kvs_get_index(char *key)
{
    uint32_t hash = 0;
    while (*key) {
        hash = hash * 33 + (int)*key;
        key++;
    }

    hash %= container_size;

    return hash;
}
