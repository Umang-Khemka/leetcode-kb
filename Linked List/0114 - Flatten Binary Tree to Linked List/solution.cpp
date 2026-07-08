class Solution {
public:
    TreeNode* prev = nullptr;

    void preOrder(TreeNode* root) {
        if (root == nullptr)
            return;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if (prev != nullptr) {
            prev->left = nullptr;
            prev->right = root;
        }

        prev = root;

        preOrder(left);
        preOrder(right);
    }

    void flatten(TreeNode* root) {
        preOrder(root);
    }
};