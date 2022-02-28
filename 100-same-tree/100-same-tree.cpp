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
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        // base case 
        if(!p && !q) return true;
        if(p == NULL || q == NULL) return false;
        
        // recursive part 
        if(p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return false;
    }
};


/*
    
    Recursive Soluction: using DFS
        Time: O(N), and n is the num of nodes
        Space: O(log N), if it's a completely balanced tree
               O(N), if it's a completely unbalanced tree 
    Approach:
    Compare each node to the corresponding node node in the other tree
    and check if both of them is the same or not 
    
    
    
    
    
*/