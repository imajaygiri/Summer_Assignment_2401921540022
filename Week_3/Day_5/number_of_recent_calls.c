#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
typedef struct {
    size_t* arr;
    size_t first;
    size_t follower;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* rc = malloc(sizeof(RecentCounter));
    if (!rc) {
        return NULL;
    }

    rc->arr = (size_t*)calloc(10000, sizeof(size_t));
    if (!rc->arr) {
        free(rc);
        return NULL;
    }
    rc->first = 0;
    rc->follower = 0;
    return rc;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->arr[obj->first++] = t;
    while ((obj->arr[obj->first - 1] - obj->arr[obj->follower]) >
           3000) {
        // move follower forward
        obj->follower++;
    }
    return obj->first - obj->follower;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->arr);
    free(obj);
}

int main(void) {
    int args[] = {1, 100, 3001, 3002};
    int exprected[] = {1, 2, 3, 3};

    RecentCounter* rc = recentCounterCreate();
    for (int i = 0; i < sizeof(args) / sizeof(args[1]); i++) {
        size_t val = recentCounterPing(rc, args[i]);
        assert(val == exprected[i]);
    }

    recentCounterFree(rc);
}
