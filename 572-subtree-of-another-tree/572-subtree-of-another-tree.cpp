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
    
    bool isSame(TreeNode* p, TreeNode* q) {
        
        // base case 
        if(!p && !q) return true;
        if(p == NULL || q == NULL) return false;
        
        // recursive part 
        if(p->val == q->val)
            return isSame(p->left, q->left) && isSame(p->right, q->right);
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root == NULL) return false;
        if(isSame(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};


/*
    binary trees
    Are the nodes' values necessarily unique?? NO
    
    root1, root2
    and i was checking if both of them is unique
    
    when root->val == subRoot->val
        START COMPARING
    
    DFS
    

*/