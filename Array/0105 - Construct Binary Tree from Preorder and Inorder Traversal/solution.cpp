/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(int inLeft, int inRight, vector<int>& preorder, unordered_map<int,int>& mp, int &preIndex){
        if(inLeft > inRight){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preIndex++]);

        int pos = mp[root->val];

        root->left = build(inLeft, pos - 1, preorder, mp, preIndex);

        root->right = build(pos + 1, inRight, preorder, mp, preIndex);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }

        int preIndex = 0;

        return build(0, inorder.size() - 1, preorder, mp, preIndex);
    }
};