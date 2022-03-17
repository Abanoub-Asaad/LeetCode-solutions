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
    
    //Time: O(N)
    //Space: O(H)
    
    bool dfs(TreeNode* root, int cur) {
        if(!root)
            return true;
        if(root->val != cur)
            return false;
        
        return dfs(root->left, cur) && dfs(root->right, cur);
    }
    
    bool isUnivalTree(TreeNode* root) {
        return dfs(root, root->val);
    }
};