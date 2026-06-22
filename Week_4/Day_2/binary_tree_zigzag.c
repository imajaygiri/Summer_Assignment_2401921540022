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

void Vec_destroy(Vec* vec) {
    free(vec->data);
    free(vec);
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
    vec->cap = vec->len;
}

size_t Vec_len(Vec* vec) {
    return vec->len;
}

void Vec_reverse(Vec* vec) {
    size_t first = 0;
    size_t last = vec->len - 1;

    while (first < last) {
        int temp = vec->data[first];
        vec->data[first] = vec->data[last];
        vec->data[last] = temp;
        first++;
        last--;
    }
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
int** zigzagLevelOrder(struct TreeNode* root,
                       int* returnSize,
                       int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    *returnSize = 0;
    int** ans = malloc(sizeof(int*) * 2000);
    *returnColumnSizes = malloc(sizeof(int) * 2000);
    Queue* q = Queue_init();
    Queue_push(q, root);

    unsigned char move_forward = 1;
    while (!Queue_is_empty(q)) {
        size_t qsize = Queue_len(q);
        Vec* vec = vec_init();
        for (int i = 0; i < qsize; i++) {
            struct TreeNode* node = Queue_front(q);
            Queue_deque(q);
            Vec_push(vec, node->val);

            if (node->left) {
                Queue_push(q, node->left);
            }
            if (node->right) {
                Queue_push(q, node->right);
            }
        }
        if (!move_forward) {
            // reverse then push

            Vec_shrink(vec);
            Vec_reverse(vec);

            ans[*returnSize] = Vec_ptr(vec);
            (*returnColumnSizes)[*returnSize] = Vec_len(vec);
            *returnSize += 1;
        } else {
            // push normaly
            Vec_shrink(vec);
            ans[*returnSize] = Vec_ptr(vec);
            (*returnColumnSizes)[*returnSize] = Vec_len(vec);
            *returnSize += 1;
        }

        free(vec);
        move_forward = !(move_forward);
    }
    Queue_destroy(q);
    return ans;
}
