#include <stddef.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void interChangeNode(struct TreeNode* node) {
    if (!node)
        return;
    if (node->left && node->right) {
        struct TreeNode* tempNode = node->left;
        node->left = node->right;
        node->right = node->left;
    } else if (node->left) {
        node->right = node->left;
        node->left = NULL;
    } else if (node->right) {
        node->left = node->right;
        node->right = NULL;
    }
}

struct TreeNode* invertTree(struct TreeNode* root) {
    if (!root)
        return NULL;
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    interChangeNode(root);
    return root;
}
