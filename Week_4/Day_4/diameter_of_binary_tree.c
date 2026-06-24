struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int helper(struct TreeNode* node, int* d) {
    if (!node)
        return -1;
    int left = 0;
    int right = 0;
    if (node->left) {
        left = helper(node->left, d);
    }
    if (node->right) {
        right = helper(node->right, d);
    }
    *d = max(*d, left + right + 2);
    return max(left, right) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    if (!root)
        return -1;
    int d = 0;
    helper(root, &d);
    return d;
}
