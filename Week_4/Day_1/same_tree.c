#include <stdbool.h>
#include <stddef.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;

    if ((p && q) && (p->val == q->val)) {
        return true & isSameTree(p->left, q->left) &
               isSameTree(p->right, q->right);
    } else {
        return false;
    }
}
