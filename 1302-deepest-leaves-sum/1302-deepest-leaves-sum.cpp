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
    
    // bfs
    int getDeepestLeavesSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        int maxDepth = 0, ans;
        
        while(q.size()) 
        {
            ++maxDepth;
            ans = 0;
            int n = q.size();
            while(n--) 
            {
                auto cur = q.front();
                q.pop();
                if(cur->left)
                    q.push(cur->left); 
                if(cur->right)
                    q.push(cur->right);
                ans +=  cur->val;
            }
        }
        
        return (maxDepth > 1) ? ans : root->val;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        return getDeepestLeavesSum(root);
    }
};

/*
    Start from the root
    Take the longest path
    
    - Get the level of the longest path using BFS = 4
    - Iterate over all the paths and when the path's level equal to max
       sum += leafOfThisPath
    


*/