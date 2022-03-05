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
    
    int minDepth(TreeNode* root) {
        
        queue<TreeNode*> q;
        if(!root) return 0; 
        q.push(root);
        int minDepth = 1;
        
        while(q.size()) 
        {
            int n = q.size();
            while(n--) 
            {
                TreeNode* cur = q.front();
                q.pop();

                if(!cur->left && !cur->right) 
                    return minDepth;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            
            ++minDepth;
        }
        
        return minDepth;
    }
};

/*
    To get min depth in a tree, the best approach here is using 
    BFS
    
                 1
              /      \
             2        3
            / \
           4   5
    
    When i reach a null, so that's the case to return 
    
                  2
                   \
                     3
                      \
                       4
                        \
                         5
                          \
                           6
                           
    If I have an edgy tree, my solution will be to know the num of 
    
    
    [1,2,3,4,null,null,5]
    
                    1
                  /   \             
                 2     3
                /       \
               4         5
                
*/