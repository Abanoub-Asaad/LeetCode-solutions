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
    
    vector<TreeNode*> duplicates;
    unordered_map<string, int> map; //key is the path, value is how many times this path appeard
    
    string dfs(TreeNode* root) {
        if(!root)
            return "";
        
        string left = dfs(root->left);
        string right = dfs(root->right);
        string key = "(" + left + to_string(root->val) + right + ")"; //make unique string of each subtree
 
        if(map[key] != -1) // if string is not present insert and increase count
            map[key]++;
        if(map[key] > 1) // if same string found more than one time we got same subtrees
            duplicates.push_back(root), map[key] = -1; // make it -1 cause no need to insert again
        
        return key;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return duplicates;
    }
};

/*
    I think the complexity is O(N^2). It creates N strings representing the serializations of the sub-trees      for each node, and it calculates a hash value for each sting, and the length of these strings is O(N).

    If we don't take time cost of "to_string" and hash cost for string into consideration, the time would be O(n).
*/
