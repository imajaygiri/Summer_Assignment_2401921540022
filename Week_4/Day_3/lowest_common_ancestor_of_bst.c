#include <stddef.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root,
                                      struct TreeNode* p,
                                      struct TreeNode* q) {
    if (!root)
        return NULL;

    struct TreeNode* curr = root;

    while (curr) {
        // case: split
        if (p->val < curr->val && q->val > curr->val) {
            return curr;
        }

        if ((p->val > curr->val) && (q->val > curr->val)) {
            // search in right subtree
            curr = curr->right;
        } else if ((p->val < curr->val) && (q->val < curr->val)) {
            curr = curr->left;
        } else {
            return curr;
        }
        // case:
    }
    return NULL;
}
