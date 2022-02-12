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
    
    void bfs(TreeNode* root, int level, vector<int>& ans) {
        
        // base case
        if(!root)
            return;
        
        if(ans.size() < level)
            ans.push_back(root -> val);
        
        // recursive funs
        bfs(root -> right, level+1, ans);
        bfs(root -> left, level+1, ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        bfs(root, 1, ans);
        return ans;
    }
};


/*
    Tree problem 
    Get the most right side of the tree 

        root 
        /   \
      left  right 
            
    Recursion problem "BFS" 
    
    Base case: root = null
    Recusrseive funs: root -> right 

*/