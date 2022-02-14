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
        
        // base case
        if(!root || root == p || root == q)
            return root;
        
        // recurse functions
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
                    
        if(!right)
            return left;
        if(!left)
            return right;
        return root;
    }
};


/*
    ONE APPROACH:
    
        We can get the path of each p and the path of q
        Then we can compare the two pathes to get the last node that both of them are sharing

        In the second example:
        p = 5, q = 4

        the path of p from root to leaf is 
        [3,5]
        the path of q from root to leaf is 
        [3,5,2,4]

        We can notice that the LCA is 5

        But how to get the path of a specifc node in a tree?! 
    
    
    ANOTHR APPROACH:
        Already implemented
            

*/
