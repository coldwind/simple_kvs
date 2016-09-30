#include "common.h"

void *kvs_malloc(size_t size) {

    if (size <= 0) {
        return NULL;
    }

    return malloc(size);
}

void kvs_free(void *mp) {
    free(mp);
}
