#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool helper(struct TreeNode* root, int targetSum, int currSum) {
    if (targetSum == currSum &&
        (root->left == NULL && root->right == NULL)) {
        return true;
    }

    bool left = false;
    if (root->left) {
        left =
            helper(root->left, targetSum, currSum + root->left->val);
    }
    bool right = false;
    if (root->right) {
        right = helper(
            root->right, targetSum, currSum + root->right->val);
    }
    return left || right;
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (!root) {
        return false;
    }

    if ((root->left == NULL && root->right == NULL) &&
        root->val == targetSum) {
        return true;
    }
    return helper(root, targetSum, root->val);
}
