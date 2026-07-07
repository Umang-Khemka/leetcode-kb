/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* target, vector<TreeNode*>& path){
        if(root == nullptr){
            return false;
        }
        path.push_back(root);

        if(root == target){
            return true;
        }
        if(dfs(root->left,target,path) || dfs(root->right,target,path)){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        dfs(root, p, path1);
        dfs(root, q, path2);

        TreeNode* ans = nullptr;

        int i = 0;

        while(i < path1.size() && i < path2.size()) {

            if(path1[i] == path2[i])
                ans = path1[i];
            else
                break;

            i++;
        }

        return ans;
        
    }
};