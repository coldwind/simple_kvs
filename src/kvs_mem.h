typedef struct {
    uint32_t len; // name长度
    char *name; // name值
} kvs_data_str;

typedef union {
    kvs_data_str *data;
    double val;
} kvs_mem_val;

typedef struct kvs_mem_data {
    uint8_t type;
    kvs_data_str *key;
    kvs_mem_val *val;
    struct kvs_mem_data *next;
} kvs_mem_data;

typedef struct{
    // 所存的数据数量
    unsigned int count;
    // data容器数组大小
    unsigned int vector_size;
    // 容器
    kvs_mem_data *data[DEFAULT_HASH_CONTAINER];

} KVS_TABLE;

void *kvs_table_malloc();
kvs_mem_data *kvs_node_malloc();
kvs_mem_val *kvs_val_malloc();
kvs_data_str *kvs_str_malloc(uint16_t);
void kvs_table_free(void *);

void kvs_table_init(KVS_TABLE **);
void kvs_table_set(char *, void *);
void *kvs_table_get(char *);
short kvs_table_remove(char *);
static uint32_t kvs_get_index(char *key);

extern uint32_t container_size;
extern KVS_TABLE *kvs_table;
