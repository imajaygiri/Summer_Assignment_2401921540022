#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    size_t len;
    size_t cap;
} Vec;

Vec* vec_init() {
    Vec* vec = malloc(sizeof(Vec));
    vec->data = malloc(sizeof(int) * 1);
    vec->len = 0;
    vec->cap = 1;
    return vec;
}

void Vec_push(Vec* vec, int val) {
    if (vec->len == vec->cap) {
        vec->data = realloc(vec->data, sizeof(int) * vec->cap * 2);
        vec->cap *= 2;
    }
    vec->data[vec->len++] = val;
}

int* Vec_ptr(Vec* vec) {
    return vec->data;
}

void Vec_shrink(Vec* vec) {
    vec->data = realloc(vec->data, sizeof(int) * vec->len);
}

size_t Vec_len(Vec* vec) {
    return vec->len;
}

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct {
    struct TreeNode** data;
    size_t index;
    size_t cap;
    size_t len;
    size_t front;
} Queue;

Queue* Queue_init() {
    Queue* q = malloc(sizeof(Queue));
    q->data = malloc(sizeof(struct TreeNode*) * 2000);
    q->cap = 2000;
    q->len = 0;
    q->index = 0;
    q->front = 0;
    return q;
}

void Queue_push(Queue* q, struct TreeNode* node) {
    q->data[q->index] = node;
    q->index = (q->index + 1) % q->cap;
    q->len++;
}

struct TreeNode* Queue_front(Queue* q) {
    return q->data[q->front];
}

void Queue_deque(Queue* q) {
    if (q->len == 0) {
        perror("Error q is empty");
        return;
    }
    q->data[q->front] = NULL;
    q->front = (q->front + 1) % q->cap;
    q->len--;
}

unsigned char Queue_is_empty(Queue* q) {
    return q->len == 0;
}

size_t Queue_len(Queue* q) {
    return q->len;
}

void Queue_destroy(Queue* q) {
    free(q->data);
    free(q);
}

int** levelOrder(struct TreeNode* root,
                 int* returnSize,
                 int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    *returnColumnSizes = malloc(sizeof(int) * 2000);
    *returnSize = 0;
    int** ans = malloc(sizeof(int*) * 2000);

    size_t columnIndex = 0;

    Queue* q = Queue_init();
    Queue_push(q, root);
    while (!Queue_is_empty(q)) {
        size_t qsize = Queue_len(q);
        Vec* vec = vec_init();
        for (size_t i = 0; i < qsize; i++) {
            struct TreeNode* node = Queue_front(q);
            Vec_push(vec, node->val);
            Queue_deque(q);
            if (node->left) {
                Queue_push(q, node->left);
            }
            if (node->right) {
                Queue_push(q, node->right);
            }
        }
        Vec_shrink(vec);
        ans[*returnSize] = Vec_ptr(vec);
        (*returnColumnSizes)[*returnSize] = Vec_len(vec);
        *returnSize += 1;
        free(vec);
    }

    Queue_destroy(q);
    return ans;
}
