#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isMirror(struct TreeNode* leftNode, struct TreeNode* rightNode) {
    printf("called\n");
    if (leftNode == NULL && rightNode == NULL) {
        return true;
    }
    if ((leftNode == NULL && rightNode != NULL) ||
        (leftNode != NULL && rightNode == NULL)) {
        return false;
    }

    if ((leftNode->val == rightNode->val) &&
        (isMirror(leftNode->left, rightNode->right) &&
         isMirror(leftNode->right, rightNode->left))) {
        printf("%d == %d \n", leftNode->val, rightNode->val);
        return true;
    } else {
        return false;
    }

    return false;
}

bool isSymmetric(struct TreeNode* root) {
    if (!root) {
        return true;
    }

    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    return isMirror(root->left, root->right);
}

struct TreeNode* constructTree() {
    struct TreeNode* root = NULL;
    printf("Enter val: ");
    int val;
    scanf("%d", &val);

    if (val == -1) {
        return NULL;
    }
    root = malloc(sizeof(struct TreeNode));
    root->left = NULL;
    root->right = NULL;
    root->val = val;

    printf("moving left of %d \n", val);
    root->left = constructTree();
    printf("moving right of %d \n", val);
    root->right = constructTree();

    return root;
}

int main(void) {
    struct TreeNode* root = constructTree();
    int res = isSymmetric(root);
    printf("res: %d\n", res);
    return 0;
}
