#include <stddef.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    struct TreeNode* curr = root;
    while (curr) {
        if (curr->val == val) {
            return curr;
        }
        if (val < curr->val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return NULL;
}
