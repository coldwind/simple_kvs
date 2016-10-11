typedef struct {
    kvs_mem_data *next;
    char *key;
    void *val;
} kvs_mem_data;

typedef struct{

    // 所存的数据数量
    unsigned int count;

    // data容器数组大小
    unsigned int vector_size;

    // 容器
    kvs_mem_data *data[];

} KVS_TABLE;

void *kvs_malloc(size_t);
void kvs_free(void *);

void kvs_mem_init(KVS_TABLE *);
void kvs_mem_set(char *, void *);
void kvs_mem_get(char *);
void kvs_mem_remove(char *);
