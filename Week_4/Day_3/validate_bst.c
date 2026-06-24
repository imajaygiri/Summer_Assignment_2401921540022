#include <limits.h>
#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool validate(struct TreeNode* node, long long min, long long max) {
    if (!node) {
        return true;
    }
    if (node->val < min || node->val > max) {
        return false;
    }
    if (node->val < max && node->val > min &&
        validate(node->left, min, node->val) &&
        validate(node->right, node->val, max)) {
        return true;
    }
    return false;
}

bool isValidBST(struct TreeNode* root) {
    if (!root) {
        return true;
    }
    return validate(root, LLONG_MIN, LLONG_MAX);
}
