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
    
    //Time: O(M), M is all the nodes in the range [low, high]
    //Space: O(H), H is the height of the tree
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        if(root->val > high)
            return rangeSumBST(root->left, low, high);
        if(root->val < low)
            return rangeSumBST(root->right, low, high);
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

/*------------------------------------------------------------------------------
------------ Time: O(N), N is all the nodes
------------ Space: O(H), H is the height of the tree
------------ Here we are not talking an advantage of that the tree is BST
/*------------------------------------------------------------------------------
class Solution {
public:
    
    void dfs(TreeNode* root, int l, int h, int &sum) {
        
        // base case
        if(!root)
            return;
        
        if(root->val >= l && root->val <= h)
            sum += root->val;
        
        dfs(root->left, l, h, sum);
        dfs(root->right, l, h, sum);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        dfs(root, low, high, sum);
        return sum;
    }
};
---------------------------------------------------------*/