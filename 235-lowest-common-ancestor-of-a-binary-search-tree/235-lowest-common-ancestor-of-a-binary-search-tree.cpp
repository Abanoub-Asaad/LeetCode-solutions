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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
        auto cur = root;
        while(cur)
        {
            if(p->val < cur-> val && q->val < cur-> val)
                return lowestCommonAncestor(root->left, p, q);
            if(p->val > cur-> val && q->val > cur-> val)
                return lowestCommonAncestor(root->right, p, q);
            else 
                return cur;
        }
    
        return {};
    }
};

// Time: O(log n) because I'm iterating only over one subtree each time