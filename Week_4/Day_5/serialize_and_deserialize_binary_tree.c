#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
typedef struct DynString {
    char* buf;
    size_t len;
    size_t cap;
} DynString;

DynString* DynString_init(size_t cap) {
    DynString* s = malloc(sizeof(DynString));
    s->buf = malloc(sizeof(char) * cap);
    s->cap = cap;
    s->len = 0;
    return s;
}

void DynString_shrink(DynString* s) {
    s->buf = realloc(s->buf, sizeof(char) * s->len + 1);
    s->cap = s->len;
}

size_t DynString_append(DynString* s, const char* text) {
    size_t textLen = strlen(text);
    if (s->len + textLen + 1 > s->cap) {
        while (s->len + textLen + 1 > s->cap) {
            s->cap = s->cap * 2;
        }
        s->buf = realloc(s->buf, sizeof(char) * s->cap * 2);
    }
    memcpy(s->buf + s->len, text, textLen);
    s->len += textLen;
    s->buf[s->len] = '\0';
    return textLen;
}

void preorder(struct TreeNode* root, DynString** dynStr) {
    if (root == NULL) {
        DynString_append(*dynStr, "#,");
        return;
    }
    char number[32];
    snprintf(number, sizeof(number), "%d,", root->val);
    DynString_append(*dynStr, number);
    preorder(root->left, dynStr);
    preorder(root->right, dynStr);
}

char* serialize(struct TreeNode* root) {
    DynString* dynStr = DynString_init(10000);
    preorder(root, &dynStr);
    DynString_shrink(dynStr);
    char* data = dynStr->buf;
    free(dynStr);
    return data;
}

struct TreeNode* deserialize_helper(char** cursor) {
    if (**cursor == '#') {
        *cursor += 2;
        return NULL;
    }
    char* end;
    long val = strtol(*cursor, &end, 10);
    struct TreeNode* root = newNode(val);
    *cursor = end;

    if (**cursor == ',') {
        *cursor += 1;
    }

    root->left = deserialize_helper(cursor);
    root->right = deserialize_helper(cursor);
    return root;
}

struct TreeNode* deserialize(char* data) {
    return deserialize_helper(&data);
}

struct TreeNode* construct() {
    printf("val: ");
    int val;
    scanf("%d", &val);
    if (val == -1) {
        return NULL;
    }
    struct TreeNode* root = newNode(val);
    printf("left of %d\n", val);
    root->left = construct();
    printf("right of %d\n", val);
    root->right = construct();
    return root;
}

int main(void) {
    struct TreeNode* root = construct();
    char* data = serialize(root);
    puts(data);
    root = deserialize(data);
    data = serialize(root);
    puts(data);
    free(data);
    return 0;
}
