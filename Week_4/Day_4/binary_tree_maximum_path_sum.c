#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    if (!node) {
        perror("Error while creating new node");
        return NULL;
    }
    node->left = node->right = NULL;
    node->val = val;
    return node;
}

struct TreeNode* constructTree() {
    struct TreeNode* root = NULL;
    printf("Enter val: ");
    int val;
    scanf("%d", &val);
    if (val == -1) {
        return NULL;
    }
    root = newNode(val);
    printf("moving left of %d \n", val);
    root->left = constructTree();
    printf("moving right of %d \n", val);
    root->right = constructTree();

    return root;
}

int max3(int a, int b, int c) {
    int mx = a > b ? a : b;
    return mx > c ? mx : c;
}

int max2(int a, int b) {
    return a > b ? a : b;
}

int helper(struct TreeNode* node, int* maxPath) {
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL) {
        return node->val;
    }
    int left = helper(node->left, maxPath);
    int right = helper(node->right, maxPath);

    *maxPath = max2(*maxPath, left + right + node->val);
    // printf("current maxPath: %d\n", *maxPath);
    return node->val + max3(left, right, 0);
}

int maxPathSum(struct TreeNode* root) {
    if (root->left == NULL && root->right == NULL)
        return root->val;
    int path = 0;
    helper(root, &path);
    // printf("ans: %d\n", path);
    return path;
}

int main(void) {
    struct TreeNode* root = constructTree();
    maxPathSum(root);

    return 0;
}
