#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->val = val;
    return node;
}

int findInorderIdx(int* inorder, int key, int startIdx, int endIdx) {
    for (int i = startIdx; i <= endIdx; i++) {
        if (key == inorder[i]) {
            return i;
        }
    }
    return -1;
}

struct TreeNode* helper(int preLeft,
                        int preRight,
                        int inLeft,
                        int inRight,
                        int* preorder,
                        int* inorder) {
    if (preLeft > preRight || inLeft > inRight)
        return NULL;

    struct TreeNode* root = NULL;
    root = newNode(preorder[preLeft]);

    int fidx =
        findInorderIdx(inorder, preorder[preLeft], inLeft, inRight);

    root->left = helper(preLeft + 1,
                        preLeft + (fidx - inLeft),
                        inLeft,
                        fidx - 1,
                        preorder,
                        inorder);

    root->right = helper(preLeft + (fidx - inLeft) + 1,
                         preRight,
                         fidx + 1,
                         inRight,
                         preorder,
                         inorder);
    return root;
}

struct TreeNode* buildTree(int* preorder,
                           int preorderSize,
                           int* inorder,
                           int inorderSize) {
    return helper(
        0, preorderSize - 1, 0, inorderSize - 1, preorder, inorder);
}
