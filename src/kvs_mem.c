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

kvs_data_str *kvs_str_malloc(uint16_t len)
{
    kvs_data_str *data_str = (kvs_data_str *)malloc(sizeof(kvs_data_str));
    if (len < KEY_LEN)
    {
        len = KEY_LEN;
    }
    else
    {
        len *= 2;
    }

    data_str->name = (char *)malloc(len);
    memset(data_str->name, 0, len);

    return data_str;
}

kvs_mem_val *kvs_val_malloc()
{
    return (kvs_mem_val *)malloc(sizeof(kvs_mem_val));
}

void kvs_table_free(void *mp)
{
    K_TABLE_FREE(mp);
}

void kvs_table_init(KVS_TABLE **kv_table)
{
    DEBUG_PRINT_S("mem init");
    int i = 0;
    *kv_table = (KVS_TABLE *)K_TABLE_MALLOC();
    (*kv_table)->count = 0;
    (*kv_table)->vector_size = DEFAULT_HASH_CONTAINER;

    for (; i < DEFAULT_HASH_CONTAINER; i++)
    {
        (*kv_table)->data[i] = kvs_node_malloc();
        (*kv_table)->data[i]->type = KVS_TYPE_NONE;
        (*kv_table)->data[i]->val = K_NULL;
        (*kv_table)->data[i]->next = K_NULL;
    }
    DEBUG_PRINT_S("mem init");
    DEBUG_PRINT_D((*kv_table)->vector_size);
}

void kvs_table_set(char *name, void *value)
{
    uint32_t index = kvs_get_index(name);
    int i = 0;

    // check table
    uint16_t keylen = (uint16_t)strlen(name);
    uint16_t vallen = (uint16_t)strlen(value);
    uint8_t valtype = KVS_TYPE_STRING;
    kvs_mem_data *temp_data = kvs_table->data[index];

    do {
        if (temp_data->next == K_NULL)
        {
            kvs_table->data[index] = kvs_node_malloc(keylen);
            kvs_table->data[index]->next = temp_data;

            // 生成key的内存块
            kvs_table->data[index]->key = kvs_str_malloc(keylen);

            strcpy(kvs_table->data[index]->key->name, name);
            kvs_table->data[index]->key->len = keylen;

            // 校验传入的数据类型
            for (; i < vallen; i++)
            {
                if (isdigit() != 0)
                {
                    valtype = KVS_TYPE_STRING;
                    break;
                }
            }

            //strcpy(kvs_table->data[index]->val, (char *)value);
            break;
        }
        else if (strcmp(temp_data->key->name, name) == 0)
        {
            //strcpy(temp_data->val, value);
            break;
        }
        else
        {
            temp_data = temp_data->next;
        }
    }
    while (1);
}

void *kvs_table_get(char *name)
{
    uint32_t index = kvs_get_index(name);

    if (index >= container_size)
    {
        return K_NULL;
    }

    kvs_mem_data *temp_data = kvs_table->data[index];
    do {
        if (temp_data->next == K_NULL)
        {
            return K_NULL;
        }

        if (strcmp(temp_data->key->name, name) == 0)
        {
            break;
        }
        else
        {
            temp_data = temp_data->next;
        }
    }
    while (1);

    return temp_data->val;
}

short kvs_table_remove(char *name)
{
    uint32_t index = kvs_get_index(name);

    if (index >= container_size)
    {
        return 0;
    }

    kvs_mem_data *temp_data = kvs_table->data[index];
    kvs_mem_data *temp_prev_data = kvs_table->data[index];
    do {
        if (temp_data->next == K_NULL)
        {
            return 0;
        }

        if (strcmp(temp_data->key->name, name) == 0)
        {
            temp_prev_data->next = temp_data->next;
            kvs_table_free(temp_data);
            break;
        }
        else
        {
            temp_prev_data = temp_data;
            temp_data = temp_data->next;
        }
    }
    while (1);

    return 1;
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
